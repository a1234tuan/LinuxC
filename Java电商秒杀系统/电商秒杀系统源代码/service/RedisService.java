package com.example.seckill.service;
import redis.clients.jedis.params.SetParams;
import redis.clients.jedis.Jedis;
import redis.clients.jedis.JedisPool;
import java.util.Collections; // 新增包引用

public class RedisService {
    private final JedisPool jedisPool;
    //扣减库存，lua脚本防止超卖
    private static final String DECREASE_STOCK_SCRIPT =
            "local stock = tonumber(redis.call('GET', KEYS[1]));" +
                    "if not stock then return -1; end;" +
                    "if stock <= 0 then return -1; end;" +
                    "return redis.call('DECR', KEYS[1]);";
    //释放锁，lua脚本保证原子性
    private static final String RELEASE_LOCK_SCRIPT =
            "if redis.call('get', KEYS[1]) == ARGV[1] then " +
                    "return redis.call('del', KEYS[1]) else return 0 end";
    public RedisService(String host, int port) {
        this.jedisPool = new JedisPool(host, port);
    }

    // 设置库存
    public void setStock(String key, int count) {
        try (Jedis jedis = jedisPool.getResource()) {
            jedis.set(key, String.valueOf(count));
        }
    }

    // 获取库存
    public int getStock(String key) {
        try (Jedis jedis = jedisPool.getResource()) {
            String val = jedis.get(key);
            return val == null ? 0 : Integer.parseInt(val);
        }
    }

    // 原子扣库存
    public long decreaseStockSafe(String key) {
        try (Jedis jedis = jedisPool.getResource()) {
            Object result = jedis.eval(DECREASE_STOCK_SCRIPT,
                    Collections.singletonList(key),
                    Collections.emptyList());
            return (Long) result;
        }
    }
    /** 获取分布式锁 */
    public boolean tryLock(String lockKey, String lockValue, int expireSeconds) {
        try (Jedis jedis = jedisPool.getResource()) {
            SetParams params = new SetParams();
            params.nx().ex(expireSeconds); // NX + EX
            String result = jedis.set(lockKey, lockValue, params);
            return "OK".equals(result);
        }
    }
    /** 释放分布式锁（只有持有者可以释放） */
    public boolean releaseLockSafe(String lockKey, String lockValue) {
        try (Jedis jedis = jedisPool.getResource()) {
            Object result = jedis.eval(RELEASE_LOCK_SCRIPT,
                    Collections.singletonList(lockKey),
                    Collections.singletonList(lockValue));
            return (Long) result > 0;
        }
    }
    public void close() {
        jedisPool.close();
    }
}
