package com.example.seckill.util;

import java.util.BitSet;

public class BloomFilterUtil {
    private final BitSet bitSet;
    private final int size;
    private final int hashSeed = 7;

    public BloomFilterUtil(int capacity) {
        this.size = capacity;
        this.bitSet = new BitSet(size);
    }

    public void add(String value) {
        int hash = Math.abs(value.hashCode() * hashSeed) % size;
        bitSet.set(hash);
    }

    public boolean contains(String value) {
        int hash = Math.abs(value.hashCode() * hashSeed) % size;
        return bitSet.get(hash);
    }
}
