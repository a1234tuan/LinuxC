package com.example.seckill.app;

import com.example.seckill.util.LogUtil;
import java.util.logging.Logger;

public class SeckillApplication {
    private static final Logger log = Logger.getLogger(SeckillApplication.class.getName());

    public static void main(String[] args) {
        LogUtil.initLogging(); // 初始化日志
        log.info("=== 秒杀应用启动 ===");

        SeckillAppContext app = new SeckillAppContext();
        app.start();
        app.simulateRequests(10000);

        app.stop();
        log.info("=== 应用结束 ===");
    }
}
