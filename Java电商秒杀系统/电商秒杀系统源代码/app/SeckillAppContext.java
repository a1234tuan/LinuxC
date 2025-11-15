package com.example.seckill.app;
import java.util.logging.Logger;

import com.example.seckill.service.SeckillSystem;

public class SeckillAppContext {
    private final SeckillSystem system = new SeckillSystem();
    private static final Logger log = Logger.getLogger(SeckillAppContext.class.getName());

    public void start() {
        log.info("==应用开始执行秒杀任务==");
        // 初始化库存
        for (int itemId = 1; itemId <= 5; itemId++) {
            system.getRedisService().setStock("item:" + itemId, 100);
        }
        // 加载恶意用户名单
        system.loadMaliciousUsers(new long[]{2, 5, 8});
        system.startWorkers(24); // <-- 必须启动worker线程

    }


    public void simulateRequests(int totalUsers) {
        //固定抢商品1
        int targetItemId = 1;
        for (int round = 0; round < 3; round++) {
            log.info("==== Round " + round + " 秒杀开始 ====");
            system.clearRequestBloom(); // <-- 新增，保证每轮重新开始

            for (int i = 1; i <= totalUsers; i++) {
                system.processRequest(i, targetItemId);

            }
            try {
                Thread.sleep(500); // 每轮间隔 0.5 秒
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
            // 额外添加恶意用户重复请求
            system.processRequest(2, 1);
            system.processRequest(5, 3);
            system.processRequest(8, 2);
        }
    }

    public void stop() {
        log.info("=== 应用关闭，释放资源 ===");
        // 等订单状态更新任务执行完再关线程池
        try {
            Thread.sleep(5000); // 延迟5秒，等异步任务完成
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        system.shutdown();
    }
}
