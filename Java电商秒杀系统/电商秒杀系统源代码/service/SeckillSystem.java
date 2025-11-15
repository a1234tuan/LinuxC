package com.example.seckill.service;

import com.example.seckill.model.Request;
import com.example.seckill.util.BloomFilterUtil;
import com.example.seckill.util.SlidingWindowRateLimiter;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.logging.Logger;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
// SeckillSystem.java

public class SeckillSystem {
    private final RedisService redisService = new RedisService("127.0.0.1",6379);

    private final BlockingQueue<Request> requestQueue = new LinkedBlockingQueue<>(10000);
    // 正常请求去重布隆
    private BloomFilterUtil requestBloom = new BloomFilterUtil(100000);

    // 恶意用户布隆（可预先加载黑名单）
    private final BloomFilterUtil maliciousBloom = new BloomFilterUtil(10000);

    private final OrderManager orderManager = new OrderManager();
    private final ExecutorService executor = Executors.newFixedThreadPool(8);
    private final SlidingWindowRateLimiter rateLimiter = new SlidingWindowRateLimiter(20000); // 每秒最多20000个请求
    //抽签概率为 1
    private final double lotteryWinRate = 1.0;
    private static final Logger log = Logger.getLogger(SeckillSystem.class.getName());

    public RedisService getRedisService() {
        return redisService;
    }
    //新增
    public void clearRequestBloom() {
        requestBloom = new BloomFilterUtil(100000); // 重置
    }
    // 初始化恶意用户名单（模拟测试）
    public void loadMaliciousUsers(long[] badUserIds) {
        for (long uid : badUserIds) {
            maliciousBloom.add(String.valueOf(uid));  // 只用 userId 做 key
        }
    }

    public void startWorkers(int count) {
        for (int i = 0; i < count; i++) {
            executor.execute(() -> {
                while (!Thread.currentThread().isInterrupted()) {
                    try {
                        Request req = requestQueue.take();
                        processStockAndOrder(req);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
            });
        }
    }
    public void processRequest(long userId, int productId) {
        // Step1: 恶意用户过滤
        if (maliciousBloom.contains(String.valueOf(userId))) {
            log.info("恶意用户拦截! UID=" + userId);
            return;
        }
        // Step 2：滑动窗口限流
        if (!rateLimiter.tryAcquire()) {
            log.info("滑动窗口限流: 请求超速 UID=" + userId);
            return;
        }
        // Step3: 正常重复请求去重
        if (requestBloom.contains(userId + "-" + productId)) {
            log.info("重复请求被拦截 UID=" + userId);
            return;
        }
        requestBloom.add(userId + "-" + productId);

        //step 4:随机抽签资格判定
        if(Math.random() > lotteryWinRate){
            log.info("用户未中签, UID=" + userId);
            return;
        }
        // Step5: 队列容量限制
        if (!requestQueue.offer(new Request(userId, productId))) {
            log.info("请求队列已满, UID=" + userId);
            return;
        }
    }


    //启动固定数量的工作线程来消费请求队列
    private void processStockAndOrder(Request req) {
        String stockKey = "item:" + req.getProductId();
        String lockKey = "lock:" + stockKey;
        String lockValue = java.util.UUID.randomUUID().toString();

        boolean locked = redisService.tryLock(lockKey, lockValue, 5);
        if (!locked) {
            log.info("商品 " + stockKey + " 被锁定，UID=" + req.getUserId());
            return;
        }

        try {
            long stockLeft = redisService.decreaseStockSafe(stockKey);
            if (stockLeft < 0) {
                log.info("库存不足, 秒杀失败 UID=" + req.getUserId());
                return;
            }
            orderManager.createOrder(req.getUserId(), req.getProductId());
        } finally {
            redisService.releaseLockSafe(lockKey, lockValue);
        }
    }


    public void shutdown() {
        executor.shutdown();
        orderManager.shutdownScheduler();
    }
}
