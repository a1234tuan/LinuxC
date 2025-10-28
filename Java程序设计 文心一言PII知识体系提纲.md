# Java程序设计 知识体系提纲

## 第6章 文件IO (File I/O)

### 核心知识点

- 文件与目录操作
  - File类：创建、删除、重命名文件和目录
  - 文件属性：获取文件信息（大小、修改时间等）
- 文本I/O
  - Scanner与PrintWriter：读写文本文件
  - BufferedReader与BufferedWriter：缓冲读写文本
- 二进制I/O
  - InputStream与OutputStream：字节流基础
  - FileInputStream与FileOutputStream：文件字节流
  - DataInputStream与DataOutputStream：数据流
  - ObjectInputStream与ObjectOutputStream：对象序列化流

### 易混/易错概念

- **文本I/O与二进制I/O的区别**：文本I/O处理字符数据，二进制I/O处理字节数据，前者更易于阅读但效率较低，后者效率高但不可直接阅读。
- **缓冲流的作用**：缓冲流通过减少实际的I/O操作次数来提高性能，但需要手动刷新缓冲区。

### 前置依赖

- 掌握Java基础语法
- 理解面向对象编程的基本概念

### 学习目标

- 能够使用File类进行文件和目录操作
- 能够使用Scanner和PrintWriter进行文本文件的读写
- 能够使用FileInputStream和FileOutputStream进行二进制文件的读写
- 理解并使用对象序列化

### 学习路径

1. 阅读PPT和教材相关内容
2. 练习使用File类操作文件和目录
3. 编写程序使用Scanner和PrintWriter读写文本文件
4. 编写程序使用FileInputStream和FileOutputStream读写二进制文件
5. 实践对象序列化

### 达成标准

- 能独立完成文件和目录的创建、删除和重命名
- 能编写程序正确读写文本文件
- 能编写程序正确读写二进制文件
- 能理解并应用对象序列化

### 自测题或实践任务

1. 编写一个程序，读取一个文本文件并统计其中的单词数量。

   

2. 编写一个程序，将一个对象序列化到文件，并从文件中反序列化该对象。

   

## 第7章 集合框架 (Collections Framework)

### 核心知识点

- 集合接口与实现类
  - List接口：ArrayList, LinkedList
  - Set接口：HashSet, TreeSet
  - Map接口：HashMap, TreeMap
- 集合操作
  - 添加、删除、遍历元素
  - 排序与查找
- 泛型
  - 泛型集合：List, Set, Map<K,V>

### 易混/易错概念

- List与Set的区别

  ：List允许重复元素且有序，Set不允许重复元素且通常无序（TreeSet有序）。

  

- ArrayList与LinkedList的区别

  ：ArrayList基于动态数组，随机访问效率高；LinkedList基于链表，插入删除效率高。

  

### 前置依赖

- 掌握Java基础语法
- 理解面向对象编程的基本概念

### 学习目标

- 理解集合框架的基本结构
- 能够使用List、Set和Map接口及其实现类
- 理解并使用泛型集合

### 学习路径

1. 阅读PPT和教材相关内容
2. 练习使用ArrayList和LinkedList
3. 练习使用HashSet和TreeSet
4. 练习使用HashMap和TreeMap
5. 实践泛型集合的使用

### 达成标准

- 能根据需求选择合适的集合类
- 能独立完成集合的基本操作（添加、删除、遍历）
- 能使用泛型集合提高代码的安全性和可读性

### 自测题或实践任务

1. 编写一个程序，使用ArrayList存储学生信息，并实现添加、删除和查找功能。

   

2. 编写一个程序，使用HashMap存储学生姓名和成绩，并实现根据姓名查找成绩的功能。

   

## 第8章 多线程编程 (Multithreading)

### 核心知识点

- 线程概念
  - 进程与线程的区别
  - 线程的生命周期
- 创建线程
  - 继承Thread类
  - 实现Runnable接口
- 线程同步
  - synchronized方法与块
  - Lock接口与ReentrantLock类
- 线程调度
  - 线程优先级
  - 线程协作（join, yield, wait, notify）

### 易混/易错概念

- **线程安全**：多线程环境下对共享资源的访问需要同步，以避免数据不一致。

- 死锁

  ：多个线程互相等待对方释放资源，导致所有线程都无法继续执行。

  

### 前置依赖

- 掌握Java基础语法
- 理解面向对象编程的基本概念

### 学习目标

- 理解线程的基本概念
- 能够创建并启动线程
- 理解线程同步机制
- 能够使用线程调度策略

### 学习路径

1. 阅读PPT和教材相关内容
2. 练习通过继承Thread类和实现Runnable接口创建线程
3. 实践线程同步（synchronized方法与块）
4. 实践使用Lock接口与ReentrantLock类
5. 实践线程调度（优先级、join、yield、wait、notify）

### 达成标准

- 能根据需求创建并启动线程
- 能正确使用线程同步机制
- 能根据需求调整线程优先级和协作方式

### 自测题或实践任务

1. 编写一个程序，创建多个线程并发执行，并使用synchronized确保对共享资源的同步访问。

2. 编写一个程序，使用ReentrantLock实现线程安全的计数器。

   

## 第9章 网络编程 (Networking)

### 核心知识点

- 网络基础
  - IP地址与端口号
  - TCP/IP与UDP协议
- TCP编程
  - ServerSocket与Socket类
  - 客户端与服务器通信
- UDP编程
  - DatagramSocket与DatagramPacket类
  - 数据报通信
- Java RMI
  - 远程方法调用

### 易混/易错概念

- **TCP与UDP的区别**：TCP是面向连接的可靠协议，UDP是无连接的不可靠协议。
- **RMI的工作原理**：RMI允许对象在不同JVM之间进行方法调用，需要对象实现Serializable接口。

### 前置依赖

- 掌握Java基础语法
- 理解网络基础概念

### 学习目标

- 理解网络编程的基本概念
- 能够使用TCP进行网络通信
- 能够使用UDP进行数据报通信
- 理解并使用Java RMI

### 学习路径

1. 阅读PPT和教材相关内容
2. 练习使用ServerSocket和Socket类实现TCP通信
3. 练习使用DatagramSocket和DatagramPacket类实现UDP通信
4. 实践Java RMI

### 达成标准

- 能根据需求创建TCP客户端和服务器
- 能根据需求创建UDP发送和接收程序
- 能理解并实现Java RMI

### 自测题或实践任务

1. 编写一个TCP客户端和服务器程序，实现客户端发送消息到服务器，服务器接收并回复。
2. 编写一个UDP程序，实现发送和接收数据报。

## 第10章 数据库编程 (Database Programming)

### 核心知识点

- JDBC基础
  - 数据库连接
  - 执行SQL语句
  - 处理结果集
- 高级JDBC
  - 预编译语句（PreparedStatement）
  - 存储过程调用（CallableStatement）
  - 事务管理
- JPA
  - 实体类与持久化
  - 关联映射

### 易混/易错概念

- JDBC与JPA的区别

  ：JDBC是底层数据库访问API，JPA是高级对象关系映射框架，简化了数据库操作。

  

- 事务管理

  ：事务确保一系列数据库操作的原子性，要么全部成功，要么全部失败。

  

### 前置依赖

- 掌握Java基础语法
- 理解数据库基础概念

### 学习目标

- 理解JDBC的基本概念
- 能够使用JDBC进行数据库操作
- 理解并使用JPA进行对象持久化

### 学习路径

1. 阅读PPT和教材相关内容
2. 练习使用JDBC连接数据库并执行SQL语句
3. 实践使用PreparedStatement和CallableStatement
4. 实践事务管理
5. 实践JPA进行对象持久化

### 达成标准

- 能根据需求连接数据库并执行SQL语句
- 能使用预编译语句和存储过程
- 能管理数据库事务
- 能使用JPA进行对象持久化

### 自测题或实践任务

1. 编写一个程序，使用JDBC连接MySQL数据库，查询学生信息并显示。

   

2. 使用JPA创建一个实体类，并实现增删改查功能。

## 第11章 JavaEE

### 核心知识点

- MVC模式
  - 模型、视图、控制器
- Spring Boot
  - 项目结构
  - 依赖管理
  - Web开发
- 数据库访问
  - Spring Data JPA
  - 自定义Repository
- RESTful API
  - 控制器与请求映射
  - 参数绑定与返回值处理

### 易混/易错概念

- **MVC各层职责**：模型负责数据处理，视图负责显示，控制器负责接收请求并协调模型和视图。

- RESTful API设计

  ：RESTful API使用HTTP方法（GET、POST、PUT、DELETE）对资源进行操作，URL应简洁明了。

  

### 前置依赖

- 掌握Java基础语法
- 理解面向对象编程的基本概念
- 了解Web开发基础

### 学习目标

- 理解MVC模式
- 能够使用Spring Boot进行Web开发
- 能够使用Spring Data JPA访问数据库
- 能够设计并实现RESTful API

### 学习路径

1. 阅读PPT和教材相关内容
2. 练习使用Spring Boot创建Web项目
3. 实践使用Spring Data JPA进行数据库访问
4. 设计并实现RESTful API

### 达成标准

- 能根据需求使用Spring Boot创建Web项目
- 能使用Spring Data JPA进行数据库操作
- 能设计并实现符合RESTful风格的API

### 自测题或实践任务

1. 使用Spring Boot创建一个Web应用，实现用户信息的增删改查功能。

   

2. 设计并实现一个RESTful API，提供学生信息的查询和添加功能。

   

## 第4章 SWING GUI与JavaFX

### 核心知识点

- SWING基础
  - 组件与容器
  - 布局管理器
  - 事件监听器
- JavaFX基础
  - 场景与舞台
  - 节点与布局
  - 事件处理

### 易混/易错概念

- SWING与JavaFX的区别

  ：SWING是传统的Java GUI工具包，JavaFX是现代的GUI工具包，提供了更丰富的UI组件和效果。

  

- 事件处理机制

  ：SWING和JavaFX都使用事件监听器处理用户交互，但具体实现方式有所不同。

  

### 前置依赖

- 掌握Java基础语法

### 学习目标

- 理解SWING和JavaFX的基本概念
- 能够使用SWING创建GUI应用
- 能够使用JavaFX创建GUI应用

### 学习路径

1. 阅读PPT和教材相关内容
2. 练习使用SWING创建简单的GUI应用
3. 练习使用JavaFX创建简单的GUI应用
4. 实践事件处理机制

### 达成标准

- 能根据需求使用SWING创建GUI应用
- 能根据需求使用JavaFX创建GUI应用
- 能正确处理用户交互事件

### 自测题或实践任务

1. 使用SWING创建一个简单的计算器应用。

2. 使用JavaFX创建一个简单的登录界面，并处理登录按钮的点击事件。

   

## 第5章 异常处理 (Exception Handling)

### 核心知识点

- 异常类型
  - 检查型异常与非检查型异常
  - 自定义异常
- 异常处理机制
  - try-catch-finally
  - throws声明
  - try-with-resources

### 易混/易错概念

- 检查型异常与非检查型异常的区别

  ：检查型异常必须在代码中处理，非检查型异常可以不用处理（如NullPointerException）。

  

- finally块的作用

  ：无论是否发生异常，finally块中的代码都会执行，常用于释放资源。

  

### 前置依赖

- 掌握Java基础语法

### 学习目标

- 理解异常处理的基本概念
- 能够使用try-catch-finally处理异常
- 能够自定义异常类

### 学习路径

1. 阅读PPT和教材相关内容
2. 练习使用try-catch-finally处理异常
3. 实践自定义异常类
4. 实践try-with-resources语句

### 达成标准

- 能根据需求正确处理异常
- 能自定义异常类并使用
- 能使用try-with-resources简化资源管理

### 自测题或实践任务

1. 编写一个程序，读取文件内容并处理可能出现的IOException。

2. 自定义一个异常类，表示无效的输入，并在程序中抛出并捕获该异常。

   