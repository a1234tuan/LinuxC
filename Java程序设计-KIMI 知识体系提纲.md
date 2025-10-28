User: 请你严格按照以下要求输出结果：

一、内容结构分析

将整门课程按章节或模块进行划分（例如“第1章 Java语言概述”“第2章 数据类型与运算符”）。

对每一章节，提炼出该章的：

核心知识点（Key Concepts）：建议使用分层结构（主知识点 → 子知识点 → 关键术语）。

易混/易错概念（Misconceptions）：列出学习者常见的理解误区。

前置依赖（Prerequisites）：掌握本章前需要具备的知识。

二、学习计划建议

针对每个主要知识点，请提供：

学习目标（Learning Objective）：用动词描述应达到的能力，例如“能够使用 for 循环控制程序流程”“理解多态的运行机制”。

推荐学习路径（Learning Steps）：列出建议的学习顺序，如“先掌握语法结构 → 练习实例 → 编写小项目”。

配套资源建议（Resource Suggestions）：推荐查找资源的方向（例如“B站搜索：Java for循环 案例讲解”或“阅读《Java编程思想》第3章”）。

三、掌握标准与自我检测

为每个知识点设计：

达成标准（Mastery Criteria）：列出可验证的掌握标准，例如“能独立写出带条件判断的输入验证程序”。

自测题或实践任务（Self-test / Mini Project）：附上1~2个检验理解的小题目或实践任务。

四、最终输出格式

请以 Markdown 格式输出，层级结构清晰，例如：

# Java程序设计 知识体系提纲

## 第1章 Java语言概述
### 核心知识点
- Java的三大特性：封装、继承、多态
- JVM、JRE、JDK 的区别与关系
- 编译与解释并存机制

### 学习目标
- 理解 Java 的跨平台原理  
- 能在本地配置并运行 Java 程序

### 学习路径
1. 阅读PPT对应内容
2. 查阅Java官方文档快速入门
3. 跟随视频演示运行“Hello World”

### 达成标准
- 能手写并解释 `public static void main` 结构  
- 能解释 classpath、javac、java 命令的区别

---

## 第2章 数据类型与运算符
...

五、整体风格

输出应逻辑化、层次分明，避免单纯列知识点。

不要仅重复PPT标题，要进行“知识提炼与教学再设计”。

如检测到知识体系存在断层或跳跃，请在结果中标注“建议补充前置内容”。
Kimi: # Java程序设计 知识体系提纲

> 本提纲依据《Java程序设计（04188）2025 秋季》课程PPT内容重新梳理，按“章节 → 知识点 → 易错点 → 学习路径 → 检测任务”五级结构展开，可直接作为自学/教学路线图使用。  
> 如章节出现知识断层，已用【⚠️建议补充前置内容】标注。

---

## 第1章 Java语言概述（含环境搭建）

### 核心知识点
- Java技术体系
  - 语言规范 + 平台（JVM + API）
  - 三版本：SE / EE / ME
- 核心术语
  - JDK：开发工具包（javac/java/javadoc/jdb）
  - JRE：运行环境（JVM + 核心类库）
  - JVM：指令集 + 类加载 + 字节码执行 + GC
- 一次编译到处运行（WORA）
  - 源码 → 字节码 → 本地机器码（解释+JIT）
- GC初步
  - 分代模型（Young/Old/Metaspace）
  - 触发时机：Minor GC、Full GC、OOM

### 易混/易错概念
| 误区                         | 正解                                              |
| ---------------------------- | ------------------------------------------------- |
| “Java是解释语言，速度一定慢” | 热点代码会被JIT编译成本地码，性能接近C++          |
| “JDK安装完就能运行”          | 还需配置`JAVA_HOME`与`PATH`，否则命令行找不到工具 |
| “GC会立即回收无引用对象”     | 回收时机由JVM决定，不可预期；`System.gc()`仅建议  |

### 前置依赖
- 会使用命令行（cd、dir/ls、环境变量）
- 了解“源代码-可执行文件”基本流程

### 学习目标
① 能口述JDK/JRE/JVM关系图  
② 能在Win/Mac/Linux完成JDK安装+环境变量配置  
③ 能独立编译运行HelloWorld并解释控制台输出

### 推荐学习路径
1. 通读PPT 1.1-1.5 → 画出“源码到运行”流程图  
2. 跟随“尚硅谷/JDK安装”B站视频实操一遍  
3. 用`javac -version` `java -version`验证，截图提交

### 达成标准
- 不借助IDE，命令行完成编译运行  
- 能解释`.class`文件名与`public class`的一致性规则

### 自测题
1. 简述“字节码”与“机器码”区别  
2. 删除`PATH`中JDK路径后，再次运行`java Hello`会报什么错？如何修复？

---

## 第2章 基础语法·数据类型·运算符

### 核心知识点
- 标识符与命名规范（驼峰、关键字禁止）
- 8种基本类型（bool/char/byte/short/int/long/float/double）
  - 长度、默认值、字面量写法（`5L` `3.14f` `'A'`）
- 引用类型初识
  - String、数组、类类型
  - 栈存引用，堆存对象
- 运算符与表达式
  - 算术/关系/逻辑/位/赋值/三目
  - 自动提升规则（int → long → float → double）
  - 强制转换语法与精度丢失

### 易混/易错概念
| 误区                       | 正解                                      |
| -------------------------- | ----------------------------------------- |
| `float f = 3.5;`可通过编译 | 默认字面量是double，需写`3.5f`            |
| `5/2 == 2.5`               | 整数相除结果为整数`2`；想要小数必须先转型 |
| `char c = "A";`            | 双引号为String，单引号才是char            |

### 前置依赖
- 第1章环境已搭好
- 了解二进制、科学计数法

### 学习目标
- 能根据数值范围选择最小够用类型
- 能预判混合运算结果类型
- 能编写带键盘输入的小工具（如BMI计算器）

### 推荐学习路径
1. 阅读《Java核心技术 卷Ⅰ》第3章
2. 练习：用`Scanner`实现“输入半径求圆面积”并保留两位小数
3. 刷10道牛客网“Java运算符”专题

### 达成标准
- 无IDE提示下写出任意两类型强制转换语句
- 能解释`short s = 5; s = s + 2;`编译失败原因并改正

### 自测题
1. 代码`char x = 'A'+5; System.out.println(x);`输出？  
2. 编写程序：输入秒数，输出“xx小时xx分xx秒”格式

---

## 第3章 流程控制与方法

### 核心知识点
- 分支：if/else、switch（表达式→JDK14）
- 循环：for、while、do-while、增强for
- 跳转：break、continue、带标签退出
- 方法三要素：返回类型+方法名+参数列表
  - 实参按值传递（primitive传值，引用传“引用的值”）
  - 重载（编译期绑定）vs.重写（运行期绑定，留待继承章）

### 易混/易错概念
| 误区                               | 正解                                   |
| ---------------------------------- | -------------------------------------- |
| “Java可以像C++那样传引用”          | 永远是传值；对象变量传递的是“地址副本” |
| 方法内可以定义`static int x`       | 方法内不允许static，只能类级           |
| `return`可以出现在void方法任意位置 | 只能`return;`不能带值                  |

### 前置依赖
- 第2章数据类型与运算符

### 学习目标
- 能画出任意循环流程图
- 能把重复代码抽取成带参数/返回值的方法
- 能正确使用重载实现“同名不同参”工具类

### 推荐学习路径
1. 先手写“99乘法表”→再抽象成`printTable(int n)`方法
2. 观看“黑马程序员Java方法”视频，完成课后3道重载练习题
3. 刷LeetCode简单题：回文数、两数之和（熟悉break/continue）

### 达成标准
- 不看示例写出递归求阶乘（n≤20）
- 能在IDE外口述“交换两整数”失败案例并给出解决方案（封装成类或返回数组）

### 自测题
1. 下面代码输出？  
   ```java
   for(int i=0; i<5; i++) {
       if(i==3) continue;
       System.out.print(i);
   }
   ```
2. 编写方法`isPrime(int n)`，主函数调用打印100以内素数

---

## 第4章 数组与字符串基础

### 核心知识点
- 一维/二维数组声明、创建、初始化、length属性
- 增强for遍历 vs. 索引遍历
- 数组工具类：`Arrays.sort`/`fill`/`toString`
- String类不可变
  - 常用方法：substring、indexOf、split、equals
  - 字符串常量池机制
- StringBuilder vs. StringBuffer（线程安全）

### 易混/易错概念
| 误区                         | 正解                              |
| ---------------------------- | --------------------------------- |
| `int[] a = new int[]{};`合法 | 长度0合法，但访问`a[0]`运行期异常 |
| `str=="hello"`比较内容       | 应使用`equals`；==比较地址        |
| 数组可以直接赋值扩大         | 数组长度固定，需新建并复制        |

### 前置依赖
- 第2章基本类型与循环

### 学习目标
- 能独立实现“冒泡排序”并打印升序结果
- 能说出String不可变带来的线程安全与内存共享优势
- 能使用StringBuilder完成高频拼接（如生成CSV）

### 推荐学习路径
1. 手写“学生成绩录入→求平均→降序输出”完整程序
2. 阅读《Effective Java》第9条“优先使用StringBuilder”
3. 完成PTA/洛谷“数组”专题5题

### 达成标准
- 能在纸上手写二分查找代码并指出时间复杂度
- 能在IDEA调试窗口观察“字符串常量池”复用现象

### 自测题
1. 代码`String s = new String("abc");`创建了几个对象？  
2. 编写程序：输入一行英文，统计单词数（以空格分隔）

---

## 第5章 面向对象封装与对象

### 核心知识点
- 类成员：field/constructor/method/block/static
- 访问修饰符：private→default→protected→public
- 封装步骤：私有字段+公有getter/setter
- this关键字：区分成员/参数；调用同类构造器
- 对象实例化过程：类加载→内存分配→默认初始化→构造器→返回引用
- 包（package）与导入（import）
  - 静态导入`import static java.lang.Math.*;`
- 不可变对象设计要点：类final+字段final+无setter+深拷贝

### 易混/易错概念
| 误区                       | 正解                                               |
| -------------------------- | -------------------------------------------------- |
| “未写构造器就不能创建对象” | 编译器自动提供无参构造；一旦手写构造则不再自动生成 |
| 构造器可以写返回值         | 任何返回值都不允许，否则变为普通方法               |
| `private`字段子类无法访问  | 子类继承但不可直接访问，应通过public/protected方法 |

### 前置依赖
- 第2-4章语法基础
- 了解内存分区（栈/堆/方法区）概念

### 学习目标
- 能画出UML类图（字段+方法+可见性）
- 能写出线程安全的不可变日期类
- 能把散乱的过程式代码重构成“学生/课程/成绩”对象模型

### 推荐学习路径
1. 观看“尚硅谷Java面向对象”前10P，跟随写Account类
2. 阅读《码出高效》封装章节，完成“银行转账”案例
3. 用javadoc生成自己写的类的API文档并发布到GitHub Pages

### 达成标准
- 不看示例写出带参构造、拷贝构造、toString、equals
- 能解释`Student s = new Student();`在内存各区域发生了什么

### 自测题
1. 构造方法能否被重载？能否被重写？  
2. 设计一个`Score`类，字段仅含`int value`，要求外部只能读取不能修改

---

## 第6章 继承、多态与抽象类

### 核心知识点
- extends单继承；super调用父类构造/方法/字段
- 类初始化顺序：父静→子静→父块→父构→子块→子构
- 方法重写规则：两同两小一大（方法名参数+返回异常+访问权限）
- 多态三要素：继承、重写、父类引用指向子类对象
- 抽象类abstract：可含抽象方法，不能实例化，用于模板设计
- 模板方法模式（钩子方法留空实现）

### 易混/易错概念
| 误区                | 正解                                                         |
| ------------------- | ------------------------------------------------------------ |
| 抽象类不能含构造器  | 可以有，供子类super调用                                      |
| 多态=重载           | 重载是编译期，多态指运行期动态绑定（重写）                   |
| `super()`可写可不写 | 子类构造器首行默认隐式`super()`；若父类无无参构造必须手写`super(args)` |

### 前置依赖
- 第5章封装与对象

### 学习目标
- 能口述“方法调用绑定”在编译期与运行期的差异
- 能用抽象类+模板方法实现“游戏初始化→开始→结束”流程
- 能把几何图形（圆/矩形/三角形）抽象成继承体系并计算总面积

### 推荐学习路径
1. 手写“员工-经理-总监”薪资案例，体会super与多态
2. 阅读《Head First 设计模式》模板方法章节
3. 在LeetCode提交“面试题 10.2 形状面积排序”利用Comparable+多态

### 达成标准
- 能在纸上画出“Grandpa→Father→Son”对象创建时的完整输出顺序
- 能用`instanceof`+向下转型写出类型安全的方法

### 自测题
1. 代码：  
   ```java
   class A { void show() { System.out.println("A"); } }
   class B extends A { void show() { System.out.println("B"); } }
   A obj = new B();
   obj.show();
   ```
   输出？若把A.show改为private，还能编译吗？  
2. 设计抽象类`Shape`，含`abstract double area()`；子类Circle/Rectangle实现并测试多态数组排序（面积升序）

---

## 第7章 接口、Lambda与策略模式

### 核心知识点
- interface：纯抽象（JDK8前）→ 默认/静态/私有方法（JDK8+）
- 实现类implements多接口，弥补单继承局限
- 函数式接口@FunctionalInterface → Lambda表达式
- 常用内置接口：Comparable/Comparator、Runnable、Cloneable（标记接口）
- 策略模式：定义算法族，分别封装，让它们可互换
- 简单工厂 vs. 工厂方法 vs. 抽象工厂（创建型模式）

### 易混/易错概念
| 误区                                 | 正解                                            |
| ------------------------------------ | ----------------------------------------------- |
| 接口字段可修改                       | 隐含`public static final`，必须初始化且不可改   |
| Lambda就是匿名内部类简写             | 编译后不同（invokedynamic），性能与可读性有差异 |
| “接口可以保护不变性”因此不需要抽象类 | 接口无状态，若需共享代码或字段仍需抽象类        |

### 前置依赖
- 第6章继承与多态

### 学习目标
- 能用Comparator写出任意对象多字段排序（先面积后周长）
- 能用Lambda把匿名内部类代码压缩至一行
- 能手写策略模式解决“支付渠道/日志输出方式”切换需求

### 推荐学习路径
1. 观看“Java8新特性”Lambda章节，完成“用Lambda遍历List并过滤”
2. 阅读《Effective Java》第21条“用函数接口实现策略”
3. 小项目：订单折扣策略（满减/打折/积分）三选一，运行期动态切换

### 达成标准
- 能口述“为什么策略模式符合开闭原则”
- 能在无IDE提示下写出`Collections.sort(list, (a,b)->a.age-b.age)`

### 自测题
1. 接口中能定义private方法吗？如果可以，使用场景？  
2. 用策略模式实现“出行导航”：CarStrategy/BikeStrategy/WalkStrategy，客户端可动态设置

---

## 第8章 内部类与嵌套类（含匿名内部类）

### 核心知识点
- 成员内部类：隐式持有外部this，可访问所有外部成员
- 静态嵌套类：无外部this，只能访问外部静态成员
- 局部内部类：方法/代码块内定义，不能用public/private
- 匿名内部类：无名字，一次使用，常用于事件/回调
- 用内部类模拟“多继承”效果（同时继承两个抽象类）

### 易混/易错概念
| 误区                           | 正解                             |
| ------------------------------ | -------------------------------- |
| 内部类字节码文件名与顶层类相同 | 实际为`Outer$Inner.class`        |
| 匿名内部类可加构造函数         | 不能写构造器，只能实例初始化块   |
| 静态嵌套类可访问外部实例字段   | 只能访问静态字段，需通过对象引用 |

### 前置依赖
- 第5-7章封装/继承/接口

### 学习目标
- 能说出四种内部类各自适用场景
- 能把GUI事件监听器写成Lambda+匿名类两种形式
- 能用静态嵌套类实现“单例+Builder”线程安全组合

### 推荐学习路径
1. 手写“按钮点击计数器”分别用匿名类/Lambda实现
2. 阅读《Java编程思想》第10章内部类
3. 小练习：用成员内部类实现“Map.Entry”简易版

### 达成标准
- 能在命令行编译并运行含内部类的源码（指定`$`类名）
- 能把“线程+回调”用匿名内部类改成Lambda并保证功能一致

### 自测题
1. 为什么静态嵌套类可单独实例化而成员内部类不行？  
2. 写出代码：在方法内定义局部内部类，实现Comparable接口并排序5个对象

---

## 第9章 常用设计模式（单例/工厂/代理/回调）

### 核心知识点
- 单例：饿汉、懒汉、DCL、静态内部类、枚举（《Effective Java》推荐）
- 工厂：简单工厂、工厂方法、抽象工厂（产品族）
- 策略：定义算法族 → 封装 → 运行期互换（已在前章）
- 代理：静态代理、动态代理（JDK Proxy/CGLIB）、AOP基础
- 回调：接口回调 = 解耦调用方→被调用方（事件驱动）

### 易混/易错概念
| 误区                  | 正解                                             |
| --------------------- | ------------------------------------------------ |
| DCL单例不需要volatile | 必须volatile防指令重排，否则可能拿到半初始化对象 |
| 工厂模式一定优于new   | 简单对象直接new即可，过度设计增加复杂度          |
| 动态代理只能代理接口  | JDK Proxy只能接口；CGLIB可代理类但需继承         |

### 前置依赖
- 第5-8章全部OOP特性
- 了解反射（Class/forName）

### 学习目标
- 能现场手写“线程安全+反射防御+序列化防御”单例
- 能根据产品等级结构选择“工厂方法”或“抽象工厂”
- 能用JDK Proxy给任意接口生成日志代理并测量耗时

### 推荐学习路径
1. 阅读《设计模式之禅》单例+工厂+代理章节
2. 观看“黑马设计模式”视频，完成课后源码
3. 小项目：给Service层所有方法加“耗时日志”动态代理，零业务代码侵入

### 达成标准
- 能在纸上画出单例DCL流程图并解释每行volatile作用
- 能把“文件解析器”用简单工厂重构，支持csv/json/xml扩展

### 自测题
1. 枚举单例如何防止反射攻击？  
2. 写代码：用Proxy.newProxyInstance为List接口生成“添加元素耗时”代理

---

## 第10章 异常体系与基础I/O

> ⚠️建议补充前置内容：Java异常类图、try-with-resources语法

### 核心知识点
- 异常架构：Throwable→Error、Exception→Checked/Unchecked
- 处理机制：try-catch-finally、多重catch、throw、throws
- 自定义异常：继承Exception/RuntimeException
- 基础I/O：File类、字节流(InputStream/OutputStream)、字符流(Reader/Writer)
- 资源关闭：try-with-resources + AutoCloseable

### 易混/易错概念
| 误区                             | 正解                                    |
| -------------------------------- | --------------------------------------- |
| catch(Exception e)能捕获所有错误 | 无法捕获Error（如OutOfMemoryError）     |
| finally一定执行                  | 调用System.exit()或JVM崩溃时不会执行    |
| File对象new完即创建磁盘文件      | 只是内存对象，需createNewFile()或流写入 |

### 学习目标
- 能区分何时抛出受检/非受检异常
- 能写出“读取文本文件→统计单词数→关闭流”完整代码
- 能用自定义异常实现“业务规则校验”语义化错误

### 推荐学习路径
1. 阅读《Java核心技术》卷Ⅰ第7章异常、第9章I/O
2. 练习：用BufferedReader逐行读取日志，找出ERROR级别行数
3. 小项目：实现“文件复制带进度百分比”控制台程序

### 达成标准
- 能在无IDE提示下写出try-with-resources三件套（try括号内声明资源）
- 能解释“异常链”机制并打印完整堆栈

### 自测题
1. 代码：  
   ```java
   try(FileReader r = new FileReader("a.txt")){ }
   catch(IOException e){ throw new RuntimeException(e); }
   ```
   是否还需finally关闭？  
2. 写方法：`copyFile(String src, String dst)`，带进度条（每10%打印一次）

---

## 第11章 集合框架（Collection & Map）

> ⚠️建议补充前置内容：泛型基础、迭代器模式、equals/hashCode契约

### 核心知识点
- 体系总览：Collection→List/Set/Queue；Map独立
- 常用实现：ArrayList、LinkedList、HashSet、LinkedHashSet、HashMap、TreeMap
- 底层结构：数组+链表+红黑树、负载因子、扩容机制
- 迭代器、forEach、Lambda遍历
- Collections工具类：sort、reverse、shuffle、 synchronizedXxx
- 泛型：类型安全、通配符`<? extends T>` vs. `<? super T>`

### 易混/易错概念
| 误区                      | 正解                                         |
| ------------------------- | -------------------------------------------- |
| HashSet能保证元素有序     | 无序；要顺序用LinkedHashSet                  |
| ArrayList线程安全         | 非同步；多线程用Vector或CopyOnWriteArrayList |
| 重写equals即可用于HashMap | 必须同时重写hashCode，否则散列冲突           |

### 学习目标
- 能根据“插入/查询/排序/线程安全”需求选择合适集合
- 能用泛型写出类型安全的工具方法（如`public static <T> List<T> toList(T... a)`）
- 能解释HashMap在JDK8的“数组+链表+红黑树”转换条件

### 推荐学习路径
1. 观看“黑马集合框架”视频，跟画体系图
2. 阅读《Java性能优化权威指南》HashMap扩容章节
3. 小项目：统计英文文章单词频率并输出Top10（用HashMap+TreeSet排序）

### 达成标准
- 能手写简易ArrayList（动态数组+扩容）
- 能说出fail-fast与fail-safe迭代器区别并给出代码示例

### 自测题
1. 代码：  
   ```java
   Set<Person> set = new HashSet<>();
   set.add(new Person("Tom", 20));
   set.add(new Person("Tom", 20));
   ```
   若Person仅重写equals未重写hashCode，set.size()=?  
2. 用Lambda将`List<String>`按字符串长度降序排序并打印

---

## 第12章 多线程基础

> ⚠️建议补充前置内容：进程 vs. 线程、Java内存模型（JMM）、上下文切换开销

### 核心知识点
- 创建方式：继承Thread、实现Runnable、Callable+Future
- 线程生命周期：NEW→RUNNABLE→BLOCKED→WAITING→TIMED_WAITING→TERMINATED
- 同步机制：synchronized（实例/静态/代码块）、显式锁ReentrantLock
- 线程通信：wait/notify/notifyAll、Condition（await/signal）
- 线程池：ExecutorService、ThreadPoolExecutor七大参数、拒绝策略
- 并发工具：CountDownLatch、CyclicBarrier、Semaphore、AtomicXxx

### 易混/易错概念
| 误区                                 | 正解                             |
| ------------------------------------ | -------------------------------- |
| run()方法直接调用算多线程            | 只有start()才会在OS创建线程      |
| synchronized锁住代码块就能保证可见性 | 还需volatile或Atomic保证变量可见 |
| ExecutorService用完无需关闭          | 必须shutdown()，否则JVM无法退出  |

### 学习目标
- 能写出“三个窗口卖100张票”线程安全版本（synchronized+锁对象）
- 能用线程池批量下载图片并统计总耗时
- 能解释“原子性、可见性、有序性”在Java中的实现手段

### 推荐学习路径
1. 阅读《Java并发编程实战》第1-3章
2. 观看“尚硅谷JUC”视频，完成CountDownLatch模拟赛跑案例
3. 小项目：多线程并发计算大文件单词总数（分块+归并）

### 达成标准
- 能手写“单例DCL+volatile”并解释禁止重排序原理
- 能用ThreadPoolExecutor自定义参数，观察不同拒绝策略效果

### 自测题
1. 代码：  
   ```java
   class Counter { int count = 0; synchronized void inc() { count++; } }
   ```
   去掉synchronized后，多线程调用结果是否一定<预期值？  
2. 写代码：用CountDownLatch实现“主线程等待三个子线程各自完成5秒任务”后统一结束

---

## 第13章 网络编程（TCP/UDP）

> ⚠️建议补充前置内容：IP/端口、OSI七层模型、Socket抽象

### 核心知识点
- Socket/ServerSocket：阻塞式BIO通信流程
- UDP：DatagramSocket/DatagramPacket，无连接、广播
- 多线程服务器：每连接一线程模型、线程池优化
- 简易协议设计：报文头+长度+内容分隔
- 短连接 vs. 长连接；心跳机制保活

### 易混/易错概念
| 误区                       | 正解                                       |
| -------------------------- | ------------------------------------------ |
| TCP比UDP一定快             | TCP有流量控制、重传，局域网可能UDP更快     |
| 关闭Socket后立刻可重用端口 | 需设置`setReuseAddress(true)`避免TIME_WAIT |
| read()返回-1表示对端已关闭 | 正确，应关闭本端Socket                     |

### 学习目标
- 能写出“客户端发送文件→服务器保存并返回确认”完整TCP程序
- 能用UDP实现局域网广播消息
- 能用线程池把“每连接一线程”改造成可承载高并发

### 推荐学习路径
1. 阅读《Java网络编程》第2-4章
2. 观看“黑马Netty入门”前导课程，理解BIO瓶颈
3. 小项目：基于TCP的多人聊天室（私聊+群聊+昵称）

### 达成标准
- 能在命令行用telnet测试自写服务器，完成收发字符串
- 能用Wireshark抓包，指出TCP三次握手与四次挥手

### 自测题
1. 代码：  
   ```java
   serverSocket = new ServerSocket(8888);
   while(true) { Socket s = serverSocket.accept(); ... }
   ```
   如何优雅地关闭该服务器？  
2. 写代码：UDP客户端发送“Hello”并接收服务器回显，设置5秒超时重发

---

## 第14章 数据库JDBC基础

> ⚠️建议补充前置内容：SQL基础（select/insert/update/delete）、主键/外键、事务ACID

### 核心知识点
- JDBC四件套：DriverManager/Connection/Statement/ResultSet
- PreparedStatement：防注入、预编译缓存
- 事务控制：setAutoCommit(false)、commit、rollback、SavePoint
- 连接池：DBCP、C3P0、HikariCP配置与监控
- ORM思想：MyBatis/JPA简介

### 易混/易错概念
| 误区                                                     | 正解                                       |
| -------------------------------------------------------- | ------------------------------------------ |
| Statement与PreparedStatement性能一样                     | 预编译+缓存，多次执行PreparedStatement更快 |
| 连接池用完不用关闭”用简单工厂重构，支持csv/xlsx/json扩展 |                                            |

### 自测题
1. 枚举单例如何防止反射攻击？  
2. 用动态代理实现“事务注解”：方法前begin，方法后commit/rollback

---

## 整体学习路线图（时间线示例）

| 周次 | 任务               | 产出                                                  |
| ---- | ------------------ | ----------------------------------------------------- |
| 1    | 第1-2章 + 环境搭建 | 在GitHub上传HelloWorld与BMI计算器                     |
| 2    | 第3章流程控制+方法 | 提交“猜数字游戏”完整版（带方法拆分）                  |
| 3    | 第4章数组+字符串   | 完成“学生成绩多维数组统计”并输出格式化报表            |
| 4    | 第5章OOP基础       | 设计“银行Account”类并生成javadoc                      |
| 5    | 第6章继承/抽象类   | 交付“几何图形面积排序”控制台程序                      |
| 6    | 第7章接口+Lambda   | 实现“支付策略”控制台Demo（含Lambda）                  |
| 7    | 第8章内部类        | 用匿名内部类+Lambda分别写“按钮监听器”                 |
| 8    | 第9章设计模式      | 提交“单例+工厂+代理”综合小项目（可记录日志的Service） |

> 建议补充前置内容：  
> 若未接触过计算机基础，请先学习“进制/内存模型/算法复杂度”再进入第1章，避免后续GC、集合性能调优出现断层。





# --------------------------------

# Java程序设计 知识体系提纲（基于10份讲义再设计）

> 说明：本提纲对原讲义进行“知识提炼+教学再设计”，将10份PDF重组为12个教学模块，并给出学习路径、易错点与自测任务。如检测到断层，用【⚠️建议补充前置内容】标出。

---

## 模块1 Java语言与生态概览（对应原“第1章”）
### 核心知识点
- Java技术栈
  - JDK ≈ 编译器+工具 / JRE ≈ JVM+核心库 / JVM ≈ 字节码运行引擎
- 跨平台机制
  - 编译→字节码→解释/即时编译→机器码
- 语言特色
  - 面向对象、自动内存管理、一次编写到处运行

### 易混/易错
- “JDK安装完就能运行”→忽略`JAVA_HOME`/`PATH`配置
- 把JVM当操作系统→混淆进程与线程边界

### 前置依赖
- 无，但需具备命令行基础（cd、dir/ls、环境变量）

### 学习目标
1. 能独立安装配置JDK并解释三者关系图
2. 能使用`javac`+`java`编译运行HelloWorld

### 学习路径
1. 10min速读官方QuickStart → 2. 跟做“HelloWorld”→ 3. 用`java -version`验证

### 达成标准
- 不借助IDE，命令行完成编译运行
- 口述`.java→.class→JIT→机器码`全过程

### 自测/任务
- 【任务】写一个打印当前JDK版本的程序
- 【题】为何同一份`.class`在Win/Mac/Linux都能跑？→简答字节码+JVM抽象

---

## 模块2 基础语法与流程控制（对应原“第2章”）
【⚠️建议补充前置内容】若学员无任意编程经验，先补“变量、赋值、布尔逻辑”通用概念

### 核心知识点
- 基本类型 vs 引用类型（栈/堆布局简图）
- 运算符优先级 & 短路求值
- 流程控制：if/else、switch（箭头语法）、三循环（for-each重点）

### 易混/易错
- `==`比较地址 vs `equals`比较内容
- `for-each`循环不能修改元素

### 学习目标
- 能选择合适循环编写1~N累加、九九表
- 能使用switch表达式返回值（Java14+）

### 学习路径
1. 画“内存条”图理解栈帧 → 2. 编写“命令行计算器”→ 3. 用调试器单步观察变量

### 达成标准
- 独立写出带输入验证的“猜数字”小游戏（while+break）

### 自测/任务
- 【题】下列代码输出？`int x=5; System.out.println(x++ + ++x);`
- 【任务】把for循环改写为while，保持结果一致

---

## 模块3 数组与集合框架（对应原“第7章”）
### 核心知识点
- 数组：定长、连续内存、索引越界检查
- 集合体系
  - Collection：List(ArrayList/LinkedList)、Set(HashSet/TreeSet)
  - Map：HashMap（桶+链表+红黑树）、TreeMap
- 泛型`<T>`：编译期擦除、通配符`? extends/super`

### 易混/易错
- 数组`length`字段 vs String`length()`方法
- `==`判等集合→用`equals`+`hashCode`

### 前置依赖
- 模块2流程控制；理解引用类型

### 学习目标
- 能根据场景选择ArrayList/HashSet/HashMap
- 能自定义类正确实现`equals&hashCode`

### 学习路径
1. 手写“学生成绩表”增删改查→2. 用JMH测ArrayList vs LinkedList随机插入→3. 读《Effective Java》第3章

### 达成标准
- 无IDE自动补全，手写泛型方法`public static <T> void swap(List<T> list, int i, int j)`

### 自测/任务
- 【题】为何向`List<Object>`不能赋值`List<String>`？→答：泛型不变性
- 【任务】实现`countWords(String txt)`返回`Map<String,Integer>`词频

---

## 模块4 面向对象三大特性（对应原“第3章前半”）
### 核心知识点
- 封装：private+public getter/setter、不可变类（final字段）
- 继承：单继承、方法重写@Override、super调用
- 多态：编译时（重载）vs 运行时（动态绑定）、接口多态

### 易混/易错
- 重载只看“编译期类型”；动态绑定只看“运行时类型”
- 字段无多态：访问看声明类型

### 学习目标
- 能画出类图并解释is-a/has-a
- 能用接口实现策略模式替换if-else

### 学习路径
1. 完成“图形面积计算器”（父类Shape+子类Circle/Rect）→2. 用接口`PaymentStrategy`实现微信/支付宝切换

### 达成标准
- 在不修改老代码前提下，通过新增类扩展功能（开闭原则）

### 自测/任务
- 【题】输出？`Base b = new Sub(); System.out.println(b.x);`（字段x在Base/Sub分别为1/2）
- 【任务】写`Filter`接口及`CoffeeFilter`/`TeaFilter`实现，演示多态

---

## 模块5 异常体系与健壮性（对应原“第5章”）
### 核心知识点
- 异常层次：Throwable→Error/Exception→Checked/Unchecked
- 关键句：try-catch-finally、throws、throw、try-with-resources
- 自定义异常：业务语义（如`InvalidRadiusException`）

### 易混/易错
- `finally`里return会吞掉异常
- 捕获`Exception`顺序：先子类后父类

### 前置依赖
- 模块2基础语法；理解方法调用栈

### 学习目标
- 能区分“可恢复”与“不可恢复”场景，正确选择受检/非受检
- 能编写带资源释放的代码（AutoCloseable）

### 学习路径
1. 改写“文件复制”用try-with-resources → 2. 为模块4图形计算器加“非法半径”自定义异常

### 达成标准
- 在方法契约中（javadoc）用`@throws`声明受检异常，并提供恢复策略

### 自测/任务
- 【题】下面代码输出？`try{throw new RuntimeException("A");}catch(Exception e){System.out.println("C");}finally{System.out.println("F");}`
- 【任务】写`LoginException`（受检）+`LoginService`，主流程捕获后提示用户重新输入

---

## 模块6 文件与I/O（对应原“第6章”）
### 核心知识点
- 文件抽象File类：路径、权限、遍历
- 字节流：InputStream/OutputStream→文件/缓冲/数据/对象流
- 字符流：Reader/Writer→转换流（InputStreamReader）
- 序列化：Serializable标记接口、serialVersionUID、transient

### 易混/易错
- 读写文本用Writer，读图片用Stream
- 未flush/close导致空文件

### 前置依赖
- 模块5异常（I/O方法均声明IOException）

### 学习目标
- 能根据“文本/二进制、随机/顺序”选择流组合
- 能用对象流实现“学生列表”持久化与读取

### 学习路径
1. 完成“图片复制”测速（字节缓冲8KB vs 1KB）→2. 写“通讯录”保存为`.dat`，下次启动恢复

### 达成标准
- 用try-with-resources一行代码完成“文本文件→ArrayList<String>”

### 自测/任务
- 【题】为何`ObjectOutputStream`写对象后修改类会抛`InvalidClassException`？
- 【任务】实现`Settings`类，把属性存到`app.config`，启动时自动加载

---

## 模块7 JavaFX & Swing GUI（对应原“第4章”）
【⚠️建议补充前置内容】事件驱动概念、匿名内部类（模块4）

### 核心知识点
- 事件模型：源对象→事件对象→监听器（接口/适配器）
- Swing顶级容器：JFrame→JPanel→布局管理器（BorderLayout等）
- JavaFX：Stage→Scene→Pane→Node；属性绑定、CSS样式
- 线程规则：Swing EDT、JavaFX Application Thread

### 易混/易错
- 直接在main线程更新UI→界面卡死
- 忘记`setVisible(true)`或`stage.show()`

### 学习目标
- 能使用SceneBuilder+FXML快速搭建表单
- 能为按钮绑定事件并验证输入

### 学习路径
1. 5min手绘界面草图→2. SceneBuilder拖控件→3. 控制器写事件→4. 打包可运行jar

### 达成标准
- 独立写出“登录+跳转到主窗口”双界面程序（FXML+控制器）

### 自测/任务
- 【题】为何`Button`的`setOnAction`参数是`EventHandler<ActionEvent>`而不是`ActionListener`？
- 【任务】实现“秒表”：开始/暂停/重置，用`Timeline`更新Label

---

## 模块8 多线程与并发（对应原“第8章”）
【⚠️建议补充前置内容】栈帧、阻塞概念（模块2+5）

### 核心知识点
- 创建方式：extends Thread vs implements Runnable vs Callable
- 生命周期：NEW→RUNNABLE→BLOCKED/WAITING/TIMED_WAITING→TERMINATED
- 同步：synchronized（monitor锁）、ReentrantLock、volatile
- 线程池：ExecutorService、submit、Callable+Future
- 死锁：四个必要条件、避免策略（顺序锁、超时、死锁检测）

### 易混/易错
- `start()` vs `run()`；线程多次start抛IllegalThreadStateException
- 锁的是对象而非代码块；String常量池锁导致死锁

### 学习目标
- 能用线程池并行计算PI蒙特卡洛，对比单核/多核耗时
- 能使用ReentrantLock+Condition写“生产者-消费者”

### 学习路径
1. 写“售票10张”发现数据错乱→2. 加synchronized→3. 改用Lock+Condition→4. 上线程池

### 达成标准
- 用`Future<T>`收集多线程返回值并合并结果

### 自测/任务
- 【题】下面代码线程安全？`private volatile int count; public void inc(){count++;}`→答：非原子
- 【任务】实现“文件夹大小统计”多线程版，速度提升>1.5×

---

## 模块9 网络编程（对应原“第9章”）
### 核心知识点
- TCP：ServerSocket+Socket；多线程/线程池-per-client
- UDP：DatagramSocket+DatagramPacket；无连接、可能丢包
- 对象传输：ObjectStream over Socket；序列化漏洞提示
- 简易HTTP：模拟Tomcat（线程池+解析GET行）

### 易混/易错
- 把`readUTF`/`writeUTF`当万能协议→与其他语言不兼容
- 未设超时→阻塞式accept/read永远挂起

### 前置依赖
- 模块6流；模块8线程池

### 学习目标
- 能写“回声服务器”支持并发客户端
- 能用UDP实现“局域网弹幕广播”

### 学习路径
1. 单线程Echo→2. 每客户端一线程→3. 线程池→4. 用Wireshark抓包观察三次握手

### 达成标准
- 用`Socket`+`ObjectOutputStream`完成“学生对象上传”客户端/服务器

### 自测/任务
- 【题】为何服务器调用`socket.close()`后客户端`read`返回-1？
- 【任务】实现“群聊室”：服务端转发消息，客户端GUI实时显示

---

## 模块10 JDBC与数据库（对应原“第10章”）
### 核心知识点
- JDBC四步：注册→连接→Statement/PreparedStatement→ResultSet
- 事务：ACID、自动提交关闭、rollback、savepoint
- 连接池：HikariCP基本配置
- ORM/JPA：实体注解、`@OneToMany`、EntityManager、JPQL

### 易混/易错
- 忘记`close`连接→数据库连接耗尽
- `?`占位符从1开始；与数组0基混淆

### 前置依赖
- SQL基础（select/insert/update）；模块5异常

### 学习目标
- 能写DAO层，把“学生”CRUD封装到`StudentRepository`
- 能用JPA完成“课程-学生”双向一对多，级联保存

### 学习路径
1. 命令行建库建表→2. 纯JDBC写DAO→3. 引入Spring Boot+JPA→4. 对比SQL与JPQL

### 达成标准
- 纯JDBC实现批量插入1000条<2s（用PreparedStatement+批处理）

### 自测/任务
- 【题】何时必须`setAutoCommit(false)`？→答：多语句组成一个业务事务
- 【任务】写“分页查询”：输入页码pageSize，返回`List<Student>`，支持模糊姓名

---

## 模块11 JavaEE与Spring Boot入门（对应原“第11章”）
【⚠️建议补充前置内容】模块10 JPA；模块7 HTTP基础

### 核心知识点
- 经典MVC：Model（JPA实体）、View（Thymeleaf）、Controller（`@RestController`）
- Spring Boot自动配置：起步依赖、内嵌Tomcat、YAML配置
- REST风格：`@GetMapping`、`@PostMapping`、JSON序列化Jackson
- 分层架构：Controller→Service→Repository（DAO）

### 易混/易错
- 把`@Controller`当`@RestController`→返回视图名而非JSON
- 循环引用导致JSON序列化栈溢出→用`@JsonIgnore`

### 学习目标
- 能启动Spring Boot并暴露`/api/students`CRUD接口
- 能用Postman测试分页、排序、模糊查询

### 学习路径
1. Spring Initializr生成项目→2. 写实体+Repo→3. 写Service→4. 写Controller→5. 集成Swagger

### 达成标准
- 打包`java -jar app.jar`独立运行，浏览器访问`/actuator/health`显示UP

### 自测/任务
- 【题】为何出现`Whitelabel Error Page`？→答：无匹配映射或模板
- 【任务】添加全局异常处理器`@RestControllerAdvice`，返回统一JSON错误体

---

## 模块12 设计模式与代码质量（对应原“第3章后半+第7章”）
### 核心知识点
- 创建型：单例（懒汉/饿汉/枚举）、工厂方法、抽象工厂、建造者
- 结构型：代理（静态+动态JDK&CGLIB）、装饰、适配器
- 行为型：策略、模板方法、观察者（Swing TableModel）、责任链
- 面向对象原则：SOLID、迪米特法则、开闭原则

### 易混/易错
- 单例双重检查忘`volatile`→指令重排拿到半初始化对象
- 动态代理必须实现接口→否则用CGLIB

### 前置依赖
- 模块4接口与多态；模块8线程安全（单例）

### 学习目标
- 能给“支付模块”画出策略模式类图并编码
- 用动态代理给Service层加日志&性能监控，不修改原类

### 学习路径
1. 手写单例→2. 用策略模式替换if-else→3. 用Proxy写AOP日志→4. 读Spring源码Template/Strategy应用

### 达成标准
- 在10min内手写线程安全单例（枚举实现），并解释为何防反射攻击

### 自测/任务
- 【题】Spring中`@Transactional`用到了哪种代理？→答：动态代理（JDK/CGLIB）
- 【任务】实现“文件解析器”工厂：输入扩展名→返回对应Parser（支持CSV/JSON/XML）

---

## 结课综合大项目（可选）
“校园二手交易平台”
- 技术栈：Spring Boot + MySQL + MyBatis + JavaFX客户端
- 功能：用户注册/登录、商品CRUD、图片上传、实时聊天（TCP）、后台统计报表
- 覆盖模块：1~12全部
- 交付物：源码+UML图+SQL脚本+演示视频

---

> 以上提纲可直接作为“Java程序设计”课程教学路线图，教师可按模块顺序授课，学生可自学并逐完成自测题与小项目，确保“学完即可干活”。







# ——————————————————————

# Java程序设计 知识体系提纲（基于教学PPT再设计）

> 说明：本提纲以“**知识-能力-任务**”为主线，对PPT内容进行**教学再设计**，可直接作为教师备课、学生自学或翻转课堂的**主线上课脚本**。  
> 如检测到断层，已用【⚠️建议补充前置内容】醒目标注。

---

## 第0章 课程导入与开发环境

| 核心知识点           | 易混/易错       | 前置依赖     |
| -------------------- | --------------- | ------------ |
| JDK/JVM/JRE 关系     | 把JDK当成“语言” | 无           |
| 命令行编译运行       | 忽略classpath   | 文件路径概念 |
| IDEA/Eclipse项目结构 | 把src当根目录   | 文件夹 vs 包 |

### 学习目标
1. 能独立安装并切换多版本JDK（含JAVA_HOME）
2. 能在命令行与IDE两种模式下运行HelloWorld

### 学习路径
1. 10分钟视频：JDK一键安装与多版本切换技巧
2. 实操：手写`HelloWorld`→`javac`→`java`
3. 进阶：在IDEA中调试断点，观察字节码文件位置

### 达成标准
- 不借助IDE，30秒内完成编译+运行
- 解释`.class`文件出现时机与存放路径

### 自测任务
Mini Project：编写脚本`run.sh`/`run.bat`，一键完成“编译→运行→清理”。

---

## 第1章 Java语言基础（语法与流程控制）

| 核心知识点         | 易混/易错          | 前置依赖     |
| ------------------ | ------------------ | ------------ |
| 8种基本类型/包装类 | 自动装箱拆箱空指针 | 二进制原反补 |
| 流程控制for-each   | 与C++范围for混淆   | 数组越界概念 |
| String不可变性     | 用==比较内容       | 对象引用模型 |

### 学习目标
- 能选用最合适的类型完成“学生成绩等级”判断程序
- 能用增强for循环遍历`List<Student>`并安全删除元素

### 学习路径
1. 可视化网站：Java Visualizer一步步看变量
2. 编码：LeetCode 412题（FizzBuzz）练手
3. 小项目：命令行“猜数字”游戏（含难度等级）

### 达成标准
- 无IDE提示下写出99乘法表（嵌套循环+格式化输出）
- 解释为什么`Integer i=128; j=128; i==j`为false

### 自测题
1. 下面代码输出什么？为什么？
   ```java
   Integer a = 1000, b = 1000;
   System.out.println(a <= b && a >= b && a != b);
   ```

---

## 第2章 数组与方法

| 核心知识点          | 易混/易错        | 前置依赖 |
| ------------------- | ---------------- | -------- |
| 引用传递 vs 值传递  | 数组作为参数     | 栈帧概念 |
| 可变参数`T... args` | 与数组实参歧义   | 方法重载 |
| 多维数组内存布局    | 仅第一维必须指定 | 指针算术 |

### 学习目标
- 能手写二分查找（递归+迭代）双版本
- 能设计方法返回“数组中第二大的元素”，并处理边界

### 学习路径
1. 图解：Debug看“值传递”过程中实参副本
2. 刷题：LeetCode 35/704题（搜索插入位置）
3. 小项目：实现`Matrix`工具类（转置、相加、打印）

### 达成标准
- 给出任意一维数组，30秒内口述排序+去重双策略
- 解释`int[][] a = new int[3][];`此时堆内存状态

### 自测任务
Mini Project：终端版2048核心算法（滑动+合并一行函数）。

---

## 第3章 面向对象程序设计（上）——类与对象

| 核心知识点          | 易混/易错                | 前置依赖     |
| ------------------- | ------------------------ | ------------ |
| 构造器重载/this()   | 与super()同时出现顺序    | 方法调用栈   |
| static/非static内存 | 静态方法内直接调用非静态 | 类加载机制   |
| 包与访问修饰符      | 默认访问权限仅限同包     | 文件系统目录 |

### 学习目标
- 能绘制UML类图并生成代码骨架（IDEA反向工程）
- 能封装“银行Account”类，保证余额不出现负值

### 学习路径
1. 视频：3D动画演示堆、方法区、栈内存
2. 实操：JUnit5为Account写单元测试（异常分支也要覆盖）
3. 小项目：实现单张扑克牌`Card`类，可比较大小

### 达成标准
- 手写代码证明“static字段被所有对象共享”
- 解释为何`main`必须public static void

### 自测题
1. 代码输出？
   ```java
   class A { static int x = 1; int y = x++; }
   public static void main(String[] args) {
       A a1 = new A(); A a2 = new A();
       System.out.println(a1.y + a2.y + A.x);
   }
   ```

---

## 第4章 面向对象程序设计（下）——继承、多态、接口

| 核心知识点        | 易混/易错                  | 前置依赖            |
| ----------------- | -------------------------- | ------------------- |
| 方法重写/重载区别 | 返回值相同才构成重写       | 字节码invokevirtual |
| 抽象类 vs 接口    | JDK8默认方法冲突           | 多继承语义          |
| 多态运行时绑定    | 向下转型ClassCastException | 类加载+虚表         |

### 学习目标
- 能重构代码消除`if-else`类型判断，改用多态
- 能设计策略模式解决“会员折扣”扩展需求

### 学习路径
1. 案例：从“形状求面积”逐步演化为策略+工厂
2. 实操：给“员工薪资系统”增加一种新职位不修改老代码
3. 小项目：插件式日志框架（支持File/Console/Network）

### 达成标准
- 手写“动物–猫–狗”演示向上/向下转型并解释虚表查找
- 解释为何“抽象类可以有构造器，接口不可以”

### 自测任务
Mini Project：实现一个命令行“计算器”，支持加减乘除及后续无限扩展新运算。

---

## 第5章 异常处理

| 核心知识点         | 易混/易错              | 前置依赖      |
| ------------------ | ---------------------- | ------------- |
| checked/unchecked  | 盲目catch(Exception e) | 异常链        |
| try-with-resources | 资源关闭顺序           | AutoCloseable |
| 自定义异常         | 继承Error              | 业务语义      |

### 学习目标
- 能区分何时抛出受检异常，何时转为运行时异常
- 能为“用户注册”模块设计语义清晰的异常体系

### 学习路径
1. 图解：异常表+栈展开过程
2. 实操：给第4章计算器增加“除零”自定义异常
3. 小项目：带重试机制的文件下载器（捕获超时异常）

### 达成标准
- 手写代码证明“finally在return之前执行”
- 解释`addSuppressed`用法及场景

### 自测题
1. 下面代码返回值？
   ```java
   int test() { try { return 1; } finally { return 2; } }
   ```

---

## 第6章 集合框架（Collection）

| 核心知识点        | 易混/易错    | 前置依赖           |
| ----------------- | ------------ | ------------------ |
| List/Set/Map语义  | 使用List查重 | equals/hashCode    |
| 迭代器fail-fast   | 并发修改异常 | 快速失败机制       |
| Collections工具类 | sort仅对List | 自然排序 vs 比较器 |

### 学习目标
- 能为不同场景（去重、缓存、排序）选择最适合的集合
- 手写`LinkedList`核心节点插入/删除算法（图示）

### 学习路径
1. 可视化：JavaFX演示各种集合增删动画
2. 刷题：LeetCode 49/347（哈希+堆）
3. 小项目：简易 LRUCache（LinkedHashMap）

### 达成标准
- 解释为何重写equals必须重写hashCode
- 无提示下实现`ArrayList`动态扩容源码级思路

### 自测任务
Mini Project：命令行“学生成绩表”——支持增删改查+多字段排序。

---

## 第7章 泛型与反射（⚠️建议补充前置内容）

| 核心知识点        | 易混/易错             | 前置依赖 |
| ----------------- | --------------------- | -------- |
| 泛型擦除          | 运行时无法获取T.class | 字节码   |
| 通配符`? super T` | PECS原则              | 里氏替换 |
| 反射访问private   | setAccessible(true)   | 访问检查 |

### 学习目标
- 能编写类型安全的通用工具类（如DAO基类）
- 能用反射+注解实现简易ORM映射

### 学习路径
1. 视频：Type Erasure对性能/代码的影响
2. 实操：写“JSON→对象”转换器（泛型+反射）
3. 小项目：迷你JUnit（@Test注解+反射执行）

### 达成标准
- 解释`List<String>.class`为何编译错误
- 手写通过反射调用私有方法的代码

### 自测题
1. 写出`public static <T> T copy(T obj)`深拷贝方法签名限制并说明原因。

---

## 第8章 多线程与并发

| 核心知识点         | 易混/易错          | 前置依赖           |
| ------------------ | ------------------ | ------------------ |
| Thread vs Runnable | 直接extends Thread | 任务拆分思想       |
| synchronized锁对象 | 锁Integer缓存值    | 字节码monitorenter |
| 线程池/Executor    | 手动new Thread开销 | 队列理论           |

### 学习目标
- 能用“生产者-消费者”模式解决实际问题
- 能排查“死锁”并给出两种以上解决策略

### 学习路径
1. 图解：线程状态机+调度策略
2. 实操：给第6章LRUCache加读写锁提升并发
3. 小项目：Web爬虫（线程池+限流+断点续爬）

### 达成标准
- 手写“单例DCL”并解释volatile作用
- 用jstack演示死锁现场定位

### 自测任务
Mini Project：多线程下载器（分块+合并+进度条）。

---

## 第9章 JavaFX & Swing（GUI）

| 核心知识点         | 易混/易错           | 前置依赖   |
| ------------------ | ------------------- | ---------- |
| 事件驱动模型       | 阻塞EDT导致界面卡死 | 观察者模式 |
| FXML/Scene Builder | 控制器与主类耦合    | MVC分层    |
| 自定义绘制         | 重写paintComponent  | 坐标系     |

### 学习目标
- 能独立搭建FXML+CSS+Controller的桌面应用
- 实现“画布”鼠标涂鸦并保存为png

### 学习路径
1. 官方Tutorial：Scene Builder五分钟入门
2. 实操：把第6章学生表用TableView展示
3. 小项目：带节拍器的番茄钟（多线程+GUI）

### 达成标准
- 解释EDT与JavaFX Application Thread差异
- 手写拖拽节点更新坐标代码

### 自测题
1. 代码改错：在`button.setOnAction`里执行`Thread.sleep(5000)`为何界面卡死？给出两种解决。

---

## 第10章 输入输出（I/O & NIO.2）

| 核心知识点     | 易混/易错              | 前置依赖   |
| -------------- | ---------------------- | ---------- |
| 字节/字符流    | 图片用Reader读损坏     | 编码原理   |
| 序列化版本号   | 不指定serialVersionUID | 类演化     |
| NIO Path/Files | 与File混用             | 函数式接口 |

### 学习目标
- 能选用合适流完成“文件夹递归拷贝”
- 用NIO.2写“批量重命名”工具（流式API）

### 学习路径
1. 案例：传统IO vs NIO性能对比（JMH基准）
2. 实操：实现“对象深拷贝”通过序列化
3. 小项目：日志分析器（大文件逐行+正则+统计）

### 达成标准
- 解释`transient`与`static`在序列化中的行为
- 手写“逐行读取1G文本不OOM”代码

### 自测任务
Mini Project：图片批量压缩工具（Files.walk+并行流）。

---

## 第11章 网络编程

| 核心知识点          | 易混/易错          | 前置依赖   |
| ------------------- | ------------------ | ---------- |
| TCP vs UDP          | 把UDP当“不可靠TCP” | 报文 vs 流 |
| Socket/ServerSocket | 端口占用复用       | 三次握手   |
| 多线程服务器        | 每连接一线程瓶颈   | 线程池     |

### 学习目标
- 能编写“群聊室”支持多人同时在线
- 用NIO.2实现单线程非阻塞EchoServer

### 学习路径
1. 实操：Wireshark抓包看三次握手
2. 小项目：文件传输带断点续传（TCP+协议设计）
3. 拓展：用WebSocket实现网页版聊天（升级HTTP）

### 达成标准
- 解释为何`readUTF`与`writeUTF`必须成对
- 给出“端口已被占用”两种编程级解决方案

### 自测题
1. 代码填空：在服务器端，如何获取客户端真实IP？

---

## 第12章 JDBC与数据库

| 核心知识点           | 易混/易错          | 前置依赖   |
| -------------------- | ------------------ | ---------- |
| 连接池/Statement缓存 | 每次new Connection | 数据库基础 |
| SQL注入              | 拼接字符串         | 预编译原理 |
| 事务ACID             | 自动提交导致脏数据 | 锁概念     |

### 学习目标
- 能用连接池+DAO+DTO完成“学生管理”增删改查
- 手写事务模板：转账+回滚演示

### 学习路径
1. 实操：DBeaver建模→逆向生成JPA实体
2. 小项目：RESTful成绩查询（Spring Boot + JPA）
3. 拓展：读写分离+乐观锁（@Version）

### 达成标准
- 解释`SERIALIZABLE`与`READ_COMMITTED`差异
- 用代码证明“丢失更新”及解决方案

### 自测任务
Mini Project：命令行“图书管理系统”——支持多表联合查询+分页。

---

## 第13章 综合项目实战（Capstone）

### 项目选项
A. 桌面端：JavaFX+MySQL“健身房会员系统”  
B. 网络端：Swing+Socket“局域网五子棋对战”  
C. 移动端：Android简化版“记账本”（Kotlin互操作）

### 里程碑
| 周次 | 任务            | 交付              |
| ---- | --------------- | ----------------- |
| 1    | 需求+原型+ER图  | PRD、UML          |
| 2    | 敏捷迭代①       | 登录+主界面       |
| 3    | 敏捷迭代②       | 核心功能          |
| 4    | 测试+CodeReview | JUnit报告、PMD    |
| 5    | 打包+发布       | exe/jar、安装手册 |

### 达成标准
- 通过Checkstyle零警告
- 单测覆盖率≥60%
- 现场答辩：随机换需求，5分钟内给出扩展方案

---

## 附录：工具与资源速查

| 工具     | 用途          | 教程入口           |
| -------- | ------------- | ------------------ |
| JShell   | 快速验证语法  | `jshell> /help`    |
| VisualVM | 性能/线程监控 | 插件Visual GC      |
| JMH      | 微基准测试    | openjdk/jmh        |
| Maven    | 依赖+构建     | 菜鸟教程10分钟入门 |
| PlantUML | 绘制时序/类图 | VS Code插件        |

---

> 使用说明  
> 1. 教师：按“章节→知识点→任务”直接翻转课堂，学生课前完成自测题，课内做项目。  
> 2. 学生：每章先完成“自测题”检验基础，再挑战“Mini Project”形成作品集。  
> 3. 若遇⚠️标注，请先补充对应前置知识，否则后续会出现“听得懂、做不出”现象。