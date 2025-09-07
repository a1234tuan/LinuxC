

# 完整交互图

````mermaid
sequenceDiagram
    participant Main as 主线程
    participant Pool as 线程池
    participant Worker as Worker线程

    Main->>Pool: nThreadPoolCreate()
    Pool->>Worker: 创建并启动线程 nThreadPoolCallBack
    Worker->>Worker: pthread_cond_wait() 等待任务

    Main->>Pool: nThreadPoolPushTask(task)
    Pool->>Pool: 加锁 + 插入任务队列
    Pool->>Worker: pthread_cond_signal 唤醒 Worker

    Worker->>Pool: 取任务 LIST_REMOVE
    Worker->>Worker: 解锁
    Worker->>Worker: 执行 task_func(user_data)
    Worker->>Worker: 再次等待任务

````



# 整体概览

```mermaid
flowchart TD
    A["线程池初始化 (nThreadPoolCreate)"] --> B["创建多个 Worker 线程"]
    B --> C["每个 Worker 执行 nThreadPoolCallBack"]
    C --> D["Worker 等待任务 (条件变量)"]
    D --> E["主线程提交任务 (nThreadPoolPushTask)"]
    E --> F["signal 唤醒等待的 Worker"]
    F --> G["Worker 取任务执行"]
    G --> D

```

###  **Worker 线程的执行逻辑 (nThreadPoolCallBack)**



```mermaid
flowchart TD
    A["Worker 线程启动"] --> B["加锁 pthread_mutex_lock"]
    B --> C{"任务队列是否为空?"}
    C -->|是| D["条件等待 pthread_cond_wait"]
    D --> B
    C -->|否| E["取出任务 LIST_REMOVE"]
    E --> F["解锁 pthread_mutex_unlock"]
    F --> G["执行任务 task->task_func(user_data)"]
    G --> B

```

## 提交任务 (nThreadPoolPushTask) 的逻辑



```mermaid
flowchart TD
    A["提交任务"] --> B["加锁 pthread_mutex_lock"]
    B --> C["插入任务到任务队列 LIST_INSERT"]
    C --> D["发信号 pthread_cond_signal"]
    D --> E["解锁 pthread_mutex_unlock"]
    E --> F["结束"]

```



## 线程池销毁 (nThreadPoolDestroy) 的逻辑

```mermaid
flowchart TD
    A["销毁线程池"] --> B["标记每个 Worker terminate=1"]
    B --> C["加锁"]
    C --> D["条件广播 pthread_cond_broadcast"]
    D --> E["解锁"]
    E --> F["等待 Worker 退出并释放资源"]

```

