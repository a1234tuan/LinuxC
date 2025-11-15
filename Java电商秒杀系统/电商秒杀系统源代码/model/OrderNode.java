package com.example.seckill.model;

public class OrderNode {
    private final long orderId;
    private final long userId;
    private final int productId;
    private OrderStatus status;

    public OrderNode(long orderId, long userId, int productId, OrderStatus status) {
        this.orderId = orderId;
        this.userId = userId;
        this.productId = productId;
        this.status = status;
    }

    public void setStatus(OrderStatus status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "Order{" +
                "orderId=" + orderId +
                ", userId=" + userId +
                ", productId=" + productId +
                ", status=" + status +
                '}';
    }
}
