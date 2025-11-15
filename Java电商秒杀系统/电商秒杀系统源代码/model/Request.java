package com.example.seckill.model;

public class Request {
    private final long userId;
    private final int productId;

    public Request(long userId, int productId) {
        this.userId = userId;
        this.productId = productId;
    }

    public long getUserId() {
        return userId;
    }

    public int getProductId() {
        return productId;
    }
}
