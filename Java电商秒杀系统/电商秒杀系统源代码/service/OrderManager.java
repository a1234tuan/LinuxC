package com.example.seckill.service;
import java.util.concurrent.atomic.AtomicLong; // 新增包引用

import com.example.seckill.model.OrderNode;
import com.example.seckill.model.OrderStatus;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.logging.Logger;

public class OrderManager {
    private final ConcurrentHashMap<Long, OrderNode> orderMap = new ConcurrentHashMap<>();
    private final ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(4);
    private static final Logger log = Logger.getLogger(OrderManager.class.getName());
    private final AtomicLong orderIdGenerator = new AtomicLong();

    public void createOrder(long userId, int productId) {
        long orderId = orderIdGenerator.incrementAndGet();
        OrderNode node = new OrderNode(orderId, userId, productId, OrderStatus.CREATED);
        // 直接放地图中，无需链表结构
        orderMap.put(orderId, node);
        log.info("创建订单成功: " + node);
        int payDelay = 1 + (int)(Math.random() * 3);
        scheduler.schedule(() -> {
            updateStatus(orderId, OrderStatus.PAID);
            int finishDelay = 1 + (int)(Math.random() * 2);
            scheduler.schedule(() -> updateStatus(orderId, OrderStatus.FINISHED),
                    finishDelay, TimeUnit.SECONDS);
        }, payDelay, TimeUnit.SECONDS);
    }

    public void updateStatus(long orderId, OrderStatus newStatus) {
        OrderNode node = orderMap.get(orderId);
        if (node != null) {
            node.setStatus(newStatus);
            log.info("订单状态更新: " + node);
        }
    }

    public void shutdownScheduler() {
        scheduler.shutdown();
    }
}
