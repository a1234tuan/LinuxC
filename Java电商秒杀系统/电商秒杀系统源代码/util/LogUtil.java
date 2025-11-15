package com.example.seckill.util;

import java.io.IOException;
import java.util.logging.*;

public class LogUtil {
    private static boolean initialized = false;

    public static void initLogging() {
        if (initialized) return;
        initialized = true;

        try {
            java.nio.file.Files.createDirectories(java.nio.file.Paths.get("logs"));

            // 文件日志 handler
            FileHandler fileHandler = new FileHandler("logs/seckill.log", true);
            fileHandler.setLevel(Level.INFO);
            fileHandler.setEncoding("UTF-8");

            // 控制台 handler
            ConsoleHandler consoleHandler = new ConsoleHandler();
            consoleHandler.setLevel(Level.INFO);
            consoleHandler.setEncoding("UTF-8");

            // 自定义简短格式
            Formatter simpleFormatter = new Formatter() {
                @Override
                public String format(LogRecord record) {
                    java.util.Date date = new java.util.Date(record.getMillis());
                    java.text.SimpleDateFormat sdf = new java.text.SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                    String time = sdf.format(date);
                    String level = record.getLevel().getName();
                    String loggerName = record.getLoggerName()
                            .substring(record.getLoggerName().lastIndexOf('.') + 1);
                    return String.format("%s  [%s]  %s - %s%n",
                            time,
                            level,
                            loggerName,
                            record.getMessage()
                    );
                }
            };

            fileHandler.setFormatter(simpleFormatter);
            consoleHandler.setFormatter(simpleFormatter);

            // 根 logger
            Logger rootLogger = Logger.getLogger("");
            rootLogger.setLevel(Level.INFO);

            // 移除默认的旧 Handler
            for (Handler h : rootLogger.getHandlers()) {
                rootLogger.removeHandler(h);
            }

            // 添加新 handler
            rootLogger.addHandler(fileHandler);
            rootLogger.addHandler(consoleHandler);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
