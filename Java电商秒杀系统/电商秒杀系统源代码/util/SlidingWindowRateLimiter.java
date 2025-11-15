package com.example.seckill.util;
import java.util.concurrent.ConcurrentLinkedQueue;//新增

public class SlidingWindowRateLimiter {
    private final int maxRequestsPerSecond;
  //新增
    private final ConcurrentLinkedQueue<Long> requestTimestamps = new ConcurrentLinkedQueue<>();

    public SlidingWindowRateLimiter(int maxRequestsPerSecond) {
        this.maxRequestsPerSecond = maxRequestsPerSecond;
    }

    public boolean tryAcquire() {
        long now = System.currentTimeMillis();
        long oneSecondAgo = now - 1000;
        while (!requestTimestamps.isEmpty() && requestTimestamps.peek() < oneSecondAgo) {
            requestTimestamps.poll();
        }
        if (requestTimestamps.size() < maxRequestsPerSecond) {
            requestTimestamps.add(now);
            return true;
        }
        return false;
    }
}
