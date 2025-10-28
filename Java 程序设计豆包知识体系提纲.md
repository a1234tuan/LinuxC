# Java 程序设计 知识体系提纲

## 第 1 章 Java 语言概述

### 核心知识点

- Java 的定义与定位

- 编程语言属性：高级、健壮、面向对象、安全的编程语言

- 平台属性：包含 Java 编程 API 和 JRE（用于执行字节码）

- Java 的核心特性

- 跨平台相关：平台无关（WORA）、可移植性、结构中立

- 性能与并发：高性能（JIT 即时编译）、高并发、多线程

- 安全与稳健：安全性、稳健性、动态性

- 开发支持：分布式、开源库（Open JDK/Oracle JDK）

- Java 的版本与历史

- 三大版本：Java SE（标准版）、Java EE（企业版）、Java ME（微型版）

- 关键时间线：1991 年 Green 项目、1995 年正式发布、2010 年 Oracle 收购 Sun、LTS 版本（8/11/17/21/25）

- Java 程序运行机制

- 核心概念：JVM（Java 虚拟机）、JRE（Java 运行时环境）、JDK（Java 开发工具包）

- 执行流程：.java源文件→javac编译→.class字节码→JVM 解释执行

- 关键工具：javac（编译器）、java（解释器）、javap（反编译）、javadoc（文档生成）

- 开发环境配置

- JDK 安装：路径选择、环境变量（JAVA_HOME、Path）配置

- IDE 选择与使用：IntelliJ IDEA、Eclipse、VSCode

### 易混 / 易错概念

1. **JVM、JRE、JDK 混淆**：误认为三者功能重叠，实际 JDK 包含 JRE，JRE 包含 JVM，开发需 JDK，运行仅需 JRE。

1. **字节码与机器码混淆**：字节码是 JVM 可识别的中间代码，需 JVM 翻译为机器码才能执行，并非直接运行的机器码。

1. **跨平台原理误解**：认为 “一次编写到处运行” 无需依赖环境，实际需在目标平台安装对应 JVM。

1. **LTS 与非 LTS 版本误用**：开发生产环境时使用非 LTS 版本（如 9-10、12-16），忽略其无长期支持的风险。

### 前置依赖

- 具备基础的计算机操作能力（文件路径查找、环境变量配置）

- 了解编程语言基本概念（编译、解释、变量、函数）

- 掌握简单的命令行操作（切换目录、执行指令）

### 学习目标

- 理解 Java 的跨平台原理及 “Write Once Run Anywhere” 的实现逻辑

- 能独立完成 JDK 安装与环境变量配置，验证环境正确性

- 能手写并解释 “Hello World” 程序结构，掌握编译与运行命令

- 区分 JVM、JRE、JDK 的功能边界，明确开发与运行环境的差异

### 学习路径

1. 阅读 Java 历史与特性文档，建立宏观认知（推荐 Oracle Java 官方时间线）

1. 跟随教程完成 JDK 安装与环境变量配置，通过java -version和javac -version验证

1. 用记事本编写 “Hello World” 程序，通过命令行（javac、java）编译运行

1. 尝试用 IDE（如 Eclipse）创建项目，对比命令行与 IDE 的执行差异

1. 查阅 JDK 文档，了解javac、java命令的常用参数（如-encoding指定编码）

### 配套资源建议

- 官方文档：[Oracle Java SE 支持路线图](https://www.oracle.com/java/technologies/java-se-support-roadmap.html)

- 视频教程：B 站搜索 “Java 环境配置 2025”（选择 LTS 版本相关教程）

- 书籍：《Java 核心技术 卷 I》第 1 章 “Java 程序设计概述”

- 实践工具：Oracle JDK 官网（下载 LTS 版本）、Eclipse IDE for Java Developers

### 达成标准

- 能独立配置 Windows/macOS/Linux 任一系统的 Java 环境，解决 “javac 不是内部命令” 等常见问题

- 能完整解释 “Hello World” 程序中public class、main方法、System.out.println的作用

- 能说明 JVM 如何实现跨平台，解释字节码与机器码的转换过程

- 能区分 LTS 与非 LTS 版本的适用场景，选择合适版本进行开发

### 自测题 / 实践任务

1. **基础题**：编写一个 Java 程序，输出 “Java is my first programming language!”，并通过命令行编译运行，截图记录执行过程。

1. **理解题**：对比分析 “直接双击.class文件” 与 “用java命令运行” 的差异，说明为何前者无法正常执行。

## 第 2 章 Java 编程基础（数据类型、运算符、流程控制）

### 核心知识点

#### 2.1 标识符、变量与常量

- 标识符规则

- 组成：字母、数字、下划线（_）、美元符号（$），不能以数字开头

- 约束：不能是关键字（如class、public）、不能是true/false/null，区分大小写

- 变量与常量

- 变量：内存中的数据存储单元，语法DataType variableName = value;（如int age = 20;）

- 常量：值不可变的标识符，语法final DataType CONSTANT_NAME = VALUE;（如final double PI = 3.14159;）

- 初始化要求：方法内变量必须初始化才能使用，类成员变量有默认值（如int默认 0）

#### 2.2 数据类型

- 基本数据类型（8 种）

- 整数类型：byte（8 位）、short（16 位）、int（32 位）、long（64 位，需加L后缀）

- 浮点类型：float（32 位，需加f后缀）、double（64 位，精度更高，默认浮点类型）

- 字符类型：char（16 位 Unicode，如'A'、'\u0041'）

- 布尔类型：boolean（仅true/false，无其他取值）

- 引用数据类型

- 类类型：String（字符串，如"Java"）、Scanner（控制台输入）

- 数组类型：int[] arr、String[][] matrix

- 包装类：Integer（对应int）、Double（对应double），用于基本类型与对象转换

#### 2.3 运算符与表达式

- 算术运算符：+、-、*、/（整数除法取整）、%（取余）、++（自增）、--（自减）

- 关系运算符：==（等于）、!=（不等于）、>、<、>=、<=，结果为boolean

- 逻辑运算符：&&（短路与）、||（短路或）、!（非），用于布尔表达式

- 赋值运算符：=、+=、-=、*=、/=（隐含类型转换）

- 其他运算符：(type)（强制类型转换）、instanceof（判断对象类型）、+（字符串连接）

#### 2.4 类型转换

- 隐式转换（自动）：小范围类型→大范围类型（如int→long、float→double）

- 显式转换（强制）：大范围类型→小范围类型（如double→int，语法(int)3.14，可能丢失精度）

- 转换规则：混合运算时，低精度类型自动转换为高精度类型（如int + double结果为double）

#### 2.5 流程控制

- 分支结构

- if-else：单分支、双分支（如if (age >= 18) { ... } else { ... }）

- 嵌套if-else：多条件判断，需注意逻辑顺序

- 循环结构

- for循环：固定次数循环（如for (int i = 0; i < 10; i++) { ... }）

- while循环：先判断后执行（如while (count < 5) { ... }）

- do-while循环：先执行后判断，至少执行一次

- 增强for循环：遍历数组 / 集合（如for (int num : arr) { ... }）

- 跳转语句：break（跳出循环）、continue（跳过当前迭代）、return（返回方法结果）

#### 2.6 数组

- 一维数组

- 声明与初始化：int[] arr1 = new int[5];（默认 0）、int[] arr2 = {1,2,3};

- 访问：通过索引（0 开始），arr[0]获取第一个元素，arr.length获取长度

- 二维数组

- 声明与初始化：int[][] matrix = new int[3][4];、int[][] matrix2 = {{1,2},{3,4}}

- 访问：matrix[i][j]，matrix.length获取行数，matrix[0].length获取列数

- 数组遍历：嵌套循环遍历二维数组，注意避免数组越界异常（ArrayIndexOutOfBoundsException）

### 易混 / 易错概念

1. **float****与****double****混淆**：忽略float需加f后缀（如2.5f），直接写2.5会被识别为double，导致编译错误。

1. **整数除法误区**：认为5/2结果为2.5，实际整数除法取整，结果为2，需转换为double（如5.0/2）。

1. **==****与****equals****混淆**：比较String时用==判断地址，而非内容，正确用法是str1.equals(str2)。

1. **数组初始化错误**：声明int[] arr = new int[5];后，误认为arr[0]为null，实际int数组默认值为0。

1. **类型转换精度丢失**：强制转换double到int时，忽略小数部分直接截断（如(int)3.9结果为3，非4）。

### 前置依赖

- 掌握第 1 章的 Java 环境配置与程序执行流程

- 理解变量、数据类型的基本概念（如整数、小数、字符串）

- 具备基础的逻辑思维（条件判断、循环执行）

### 学习目标

- 能正确定义标识符、变量与常量，遵循命名规范（如变量小驼峰、常量大写下划线）

- 能区分 8 种基本数据类型的适用场景，选择合适类型存储数据（如用long存储大整数）

- 能熟练使用运算符构建表达式，解决数学计算问题（如 BMI 计算、三角形面积）

- 能运用if-else、for、while实现流程控制，编写带条件判断和循环的程序

- 能声明、初始化一维 / 二维数组，完成遍历、求和、查找等基本操作

### 学习路径

1. 先掌握标识符与变量规则，通过练习判断 “2mail”“room#” 等是否为合法标识符

1. 学习 8 种基本数据类型的范围与用法，对比int与long、float与double的差异

1. 练习运算符使用，重点掌握算术运算符的整数除法、++的前置 / 后置差异

1. 学习类型转换规则，通过实例理解隐式转换的安全与显式转换的风险

1. 依次学习分支（if-else）、循环（for/while）结构，编写 “成绩等级判断”“累加求和” 程序

1. 学习数组的声明与初始化，完成 “数组求和”“二维数组遍历” 练习，解决数组越界问题

### 配套资源建议

- 视频教程：B 站 “Java 基础 数据类型与运算符”（推荐尚硅谷、黑马程序员基础课）

- 书籍：《Java 编程思想》第 4 章 “控制执行流程”、第 5 章 “初始化与清理”

- 实践工具：IntelliJ IDEA（使用 Debug 模式观察变量值变化）

- 在线练习：LeetCode 简单题（如 “两数之和”“斐波那契数列”，用 Java 实现）

### 达成标准

- 能独立编写 “BMI 计算器” 程序：接收用户输入的身高（米）和体重（千克），计算 BMI 并判断体重等级（偏瘦 / 正常 / 超重 / 肥胖）

- 能编写 “数组统计” 程序：遍历一维数组，统计正数、负数、零的个数，并计算平均值

- 能解决 “水仙花数” 问题：找出 100~999 之间的所有水仙花数（各位数字立方和等于该数本身）

- 能避免常见错误：如整数除法精度丢失、数组越界、未初始化变量使用

### 自测题 / 实践任务

1. **基础题**：编写程序，接收用户输入的 3 个整数，找出其中最大值并输出，要求使用if-else分支结构，不使用Math.max方法。

1. **进阶题**：声明一个 3 行 4 列的二维数组，随机生成 10~99 的整数填充数组，然后计算每行的和并输出数组及每行的和（使用嵌套循环）。

## 第 3 章 面向对象程序设计（类、对象、封装、继承、多态）

### 核心知识点

#### 3.1 类与对象

- 类的定义：描述对象的模板，包含属性（成员变量）和行为（成员方法），语法：

```
public class Circle {
    // 属性（成员变量）
    private double radius;
    // 构造方法（初始化对象）
    public Circle(double radius) {
        this.radius = radius;
    }
    // 方法（行为）
    public double getArea() {
        return 3.14159 * radius * radius;
    }
}
```

- 对象的创建与使用：

- 创建：Circle c = new Circle(5.0);（new关键字分配内存，调用构造方法）

- 使用：c.getArea()（调用对象方法）、c.radius（访问属性，需权限允许）

- 构造方法：

- 作用：初始化对象，与类名同名，无返回值

- 默认构造方法：无参构造，若自定义构造方法则默认构造消失

- this关键字：指代当前对象，用于区分成员变量与参数（如this.radius = radius）

#### 3.2 封装（Encapsulation）

- 核心思想：隐藏对象的内部细节，仅通过公共方法暴露接口

- 实现方式：

- 成员变量用private修饰（私有，仅类内可访问）

- 提供public的getter（获取值，如getRadius()）和setter（设置值，如setRadius(double r)）方法

- 优势：保护数据安全（如setRadius中可校验半径合法性）、降低耦合度

#### 3.3 继承（Inheritance）

- 定义：子类（Subclass）继承父类（Superclass）的属性和方法，语法class Sub extends Super { ... }

- 核心特性：

- 单继承：Java 仅支持单继承（一个子类只能有一个直接父类）

- 继承内容：父类的public/protected成员（属性 / 方法），private成员不可直接继承

- super关键字：指代父类对象，用于调用父类构造方法（super()）或父类方法（super.getArea()）

- 构造方法链：子类构造方法默认先调用父类无参构造，若父类无无参构造，需显式调用super(参数)

#### 3.4 多态（Polymorphism）

- 定义：同一方法在不同对象上有不同实现，需满足 “继承 + 方法重写 + 父类引用指向子类对象”

- 方法重写（Override）：

- 条件：子类方法与父类方法的签名（方法名、参数列表、返回值类型）完全一致

- 约束：子类方法访问权限不能低于父类（如父类public，子类不能是private）

- 动态绑定：运行时根据对象实际类型调用对应方法（如Geo o = new Circle(); o.draw();调用Circle的draw方法）

- 类型转换：

- 向上转型（自动）：子类对象→父类引用（如Geo o = new Circle();）

- 向下转型（强制）：父类引用→子类对象（如Circle c = (Circle)o;，需用instanceof判断类型，避免ClassCastException）

#### 3.5 抽象类与接口

- 抽象类（Abstract Class）：

- 定义：包含抽象方法的类，语法abstract class Geo { abstract void draw(); }

- 特性：不能实例化，需子类继承并实现所有抽象方法；可包含非抽象方法和成员变量

- 接口（Interface）：

- 定义：行为规范的集合，JDK8 前仅含抽象方法，JDK8 后可含default（默认实现）和static方法，语法：

```
public interface Movable {
    void moveUp(); // 抽象方法，默认public abstract
    default void moveDown() { // 默认方法
        System.out.println("Moving down");
    }
}
```

- 特性：类通过implements实现接口，支持多实现（如class Circle extends Geo implements Movable, Comparable）；接口中变量默认public static final

- 区别：抽象类侧重 “is-a” 关系（如Circle is a Geo），接口侧重 “has-a” 能力（如Circle has a Movable ability）

#### 3.6 内部类

- 分类：

- 成员内部类：定义在类内部，非静态，可访问外部类所有成员（如class Outer { class Inner { ... } }）

- 静态内部类：定义在类内部，加static，不能访问外部类非静态成员（如class Outer { static class Inner { ... } }）

- 局部内部类：定义在方法 / 代码块内部，作用域仅限于该方法

- 匿名内部类：无类名，仅创建一个对象，常用于实现接口或继承抽象类（如new Runnable() { public void run() { ... } }）

- 作用：实现代码隐藏、模拟多继承（通过内部类继承多个类）、简化回调代码

### 易混 / 易错概念

1. **this****与****super****混淆**：this指代当前对象，super指代父类对象；this()调用当前类构造方法，super()调用父类构造方法，两者不能同时出现在构造方法第一行。

1. **方法重写与重载混淆**：重写（Override）是子类覆盖父类同名同签名方法，发生在继承中；重载（Overload）是同一类中同名不同参数列表方法，与继承无关。

1. **抽象类与接口混淆**：误认为抽象类可多继承，实际 Java 类仅支持单继承；接口可多实现，但接口不能包含非static非default的方法实现。

1. **多态中方法调用误解**：认为父类引用调用方法时优先执行父类方法，实际运行时根据对象实际类型调用（动态绑定），仅编译时检查父类是否有该方法。

1. **内部类访问外部类成员误解**：静态内部类不能访问外部类非静态成员，需通过外部类对象访问；局部内部类访问方法内变量时，该变量需是final（JDK8 后隐式final）。

### 前置依赖

- 掌握第 2 章的 Java 基础语法（变量、方法、数组）

- 理解面向对象的基本思想（封装、继承、多态的概念）

- 具备基础的逻辑抽象能力（能将现实事物抽象为类的属性和方法）

### 学习目标

- 能独立设计类（如Student、Circle），定义属性、构造方法、getter/setter方法，实现封装

- 能使用继承创建类层次（如Geo→Circle→Ellipse），正确使用super调用父类构造和方法

- 能实现多态：子类重写父类方法，通过父类引用调用子类方法，正确进行类型转换

- 能区分抽象类与接口的适用场景，根据需求选择使用（如用抽象类定义通用属性，用接口定义行为）

- 能使用内部类（尤其是匿名内部类）简化代码（如实现Runnable接口创建线程）

### 学习路径

1. 先学习类与对象：定义简单类（如Person），创建对象并调用方法，理解this关键字和构造方法

1. 学习封装：将类的成员变量设为private，编写getter/setter，在setter中添加数据校验（如年龄不能为负）

1. 学习继承：创建父类（如Animal）和子类（如Dog、Cat），理解super的用法，掌握构造方法链

1. 学习多态：子类重写父类方法（如Animal的sound方法），通过父类引用调用，理解动态绑定

1. 学习抽象类与接口：定义抽象类（如Geo）和接口（如Movable），实现子类和实现类，对比两者差异

1. 学习内部类：依次掌握成员内部类、静态内部类、匿名内部类，通过实例（如线程创建）理解用法

### 配套资源建议

- 视频教程：B 站 “Java 面向对象 深入理解”（推荐韩顺平、尚硅谷教程）

- 书籍：《Effective Java》第 4 章 “类和接口”、《Java 核心技术 卷 I》第 6~9 章

- 官方文档：[Oracle Java 接口教程](https://docs.oracle.com/javase/tutorial/java/IandI/index.html)

- 实践案例：设计 “简易学生管理系统”，包含Student类、StudentManager类，实现添加、查询、删除功能

### 达成标准

- 能设计 “图形计算系统”：定义抽象类Geo（含getArea、getPerimeter抽象方法），子类Circle、Rectangle实现抽象方法，通过父类引用数组存储不同图形对象并遍历计算总面积

- 能设计 “可移动对象系统”：定义Movable接口（含moveUp、moveDown方法），Circle类实现该接口，编写方法接收Movable类型参数，调用移动方法（体现多态）

- 能使用匿名内部类实现Comparator接口，对Student对象按成绩排序

- 能区分抽象类与接口的适用场景，说明 “为何Comparable是接口而非抽象类”

### 自测题 / 实践任务

1. **基础题**：设计Student类（属性：学号sno、姓名name、成绩score，封装属性，提供构造方法和getter/setter），创建Student对象数组，用Arrays.sort和匿名Comparator按成绩降序排序并输出。

1. **进阶题**：设计抽象类Shape（含getArea抽象方法），子类Circle（半径）、Triangle（三边长，用海伦公式计算面积），创建Shape数组存储 3 个Circle和 2 个Triangle对象，遍历数组计算并输出所有图形的总面积。

## 第 4 章 Java 高级编程（GUI、异常、集合、多线程、网络、数据库）

### 核心知识点

#### 4.1 异常处理（Exception Handling）

- 异常体系：

- 顶层类：Throwable，分为Error（严重错误，如OutOfMemoryError，无法处理）和Exception（可处理异常）

- Exception分类：编译时异常（如IOException，必须处理）、运行时异常（如NullPointerException，可选处理）

- 异常处理机制：

- try-catch-finally：try包裹可能出错的代码，catch捕获并处理异常，finally无论是否异常都执行（如资源关闭）

- throws：声明方法可能抛出的异常，由调用者处理

- 自定义异常：继承Exception或RuntimeException，如public class AgeException extends Exception { ... }

#### 4.2 集合框架（Collection Framework）

- 核心接口：

- Collection：存储单个元素，子接口List（有序、可重复）、Set（无序、不可重复）

- List实现类：ArrayList（动态数组，查询快）、LinkedList（链表，增删快）

- Set实现类：HashSet（哈希表，无序）、TreeSet（红黑树，有序，需实现Comparable）

- Map：存储键值对（key-value），实现类HashMap（哈希表）、TreeMap（有序）

- 常用操作：

- List：add、get、remove、size

- Set：add、contains、isEmpty

- Map：put、get、keySet、values

#### 4.3 多线程（Multithreading）

- 线程创建方式：

- 继承Thread类：重写run方法，调用start启动线程

- 实现Runnable接口：实现run方法，通过Thread对象启动（如new Thread(new MyRunnable()).start()）

- 实现Callable接口：有返回值，可抛出异常，结合FutureTask使用

- 线程状态：新建（New）→就绪（Runnable）→运行（Running）→阻塞（Blocked）→死亡（Terminated）

- 线程同步：

- 问题：多线程共享资源时出现线程安全问题（如卖票超卖）

- 解决：synchronized关键字（同步方法 / 同步代码块）、Lock接口（如ReentrantLock）

#### 4.4 输入输出（I/O）

- 流的分类：

- 按方向：输入流（InputStream/Reader）、输出流（OutputStream/Writer）

- 按数据单位：字节流（InputStream/OutputStream，处理二进制文件）、字符流（Reader/Writer，处理文本文件）

- 常用类：

- 字节流：FileInputStream、FileOutputStream

- 字符流：FileReader、FileWriter、BufferedReader（缓冲，提高效率）

- 文件操作：File类（表示文件 / 目录，如new File("test.txt")），判断文件存在、创建文件、删除文件

#### 4.5 网络编程（Network Programming）

- TCP 编程：

- 服务器端：ServerSocket监听端口，accept接收客户端连接

- 客户端：Socket连接服务器，通过InputStream/OutputStream交换数据

- UDP 编程：

- 无连接，基于DatagramSocket和DatagramPacket发送 / 接收数据

- 常用类：Socket、ServerSocket、DatagramSocket、InetAddress（表示 IP 地址）

#### 4.6 数据库操作（JDBC）

- JDBC 流程：

1. 加载数据库驱动（如Class.forName("com.mysql.cj.jdbc.Driver")）

1. 建立连接：DriverManager.getConnection(url, username, password)

1. 创建Statement/PreparedStatement对象（执行 SQL）

1. 执行 SQL：executeQuery（查询，返回ResultSet）、executeUpdate（增删改，返回影响行数）

1. 处理结果：遍历ResultSet获取数据

1. 关闭资源：ResultSet、Statement、Connection

### 易混 / 易错概念

1. **try-catch****与****throws****混淆**：try-catch是 “处理异常”，throws是 “声明异常”，后者需调用者处理；不要用throws Exception声明所有异常，应明确具体异常类型。

1. **ArrayList****与****LinkedList****误用**：频繁查询用ArrayList（随机访问快），频繁增删用LinkedList（链表节点操作快），误认为ArrayList增删一定慢（尾部增删快）。

1. **线程****start****与****run****混淆**：调用start方法启动线程（JVM 调用run），直接调用run方法仅为普通方法调用，不会启动新线程。

1. **字节流与字符流误用**：处理文本文件用字符流（避免乱码），处理图片 / 视频等二进制文件用字节流，不能混用（如用FileReader读图片会损坏文件）。

1. **JDBC 资源关闭遗漏**：未在finally中关闭Connection、Statement，导致数据库连接泄漏；应使用try-with-resources（JDK7+）自动关闭资源。

### 前置依赖

- 掌握第 3 章的面向对象编程（类、对象、接口）

- 理解异常、线程、集合的基本概念（如异常是程序运行时错误，线程是程序执行单元）

- 具备基础的数据库知识（如 SQL 语句、数据库连接概念）

### 学习目标

- 能使用try-catch-finally处理异常，自定义异常类并抛出，解决程序运行时错误（如空指针、数组越界）

- 能熟练使用ArrayList、HashMap等集合类，完成数据存储、查询、排序操作（如存储学生信息并按姓名排序）

- 能创建多线程程序，解决线程安全问题（如用 synchronized实现安全卖票）

- 能使用字节流 / 字符流读写文件，实现文本文件复制、二进制文件（如图片）复制

- 能通过 JDBC 连接 MySQL 数据库，执行增删改查操作，处理查询结果

### 学习路径

1. 先学习异常处理：理解异常体系，练习try-catch捕获运行时异常，学习throws和自定义异常

1. 学习集合框架：依次掌握List、Set、Map的常用实现类和操作，通过案例（如 “学生成绩管理”）练习

1. 学习多线程：创建简单线程（继承Thread、实现Runnable），理解线程状态，学习 synchronized解决线程安全问题

1. 学习 I/O 流：先掌握字节流读写文件，再学习字符流，对比两者差异，练习文件复制

1. 学习网络编程：先掌握 TCP 编程（客户端 - 服务器通信），再了解 UDP 编程，实现简单的聊天程序

1. 学习 JDBC：配置 MySQL 环境，加载驱动，建立连接，执行 SQL，处理结果，学习PreparedStatement防止 SQL 注入

### 配套资源建议

- 视频教程：B 站 “Java 高级编程 异常与集合”“Java JDBC 实战教程”

- 书籍：《Java 核心技术 卷 I》第 11 章 “异常、日志、断言和调试”、第 12 章 “集合”

- 工具：MySQL 数据库（社区版）、Navicat（数据库可视化工具）、Postman（测试网络接口）

- 实践案例：“文件管理器”（I/O）、“多人聊天程序”（多线程 + 网络）、“学生信息管理系统”（JDBC + 集合）

### 达成标准

- 能编写 “异常处理示例” 程序：自定义AgeOutOfRangeException，在Student类的setAge方法中判断年龄（0~150），不合法则抛出异常，在main中捕获并处理

- 能编写 “购物车程序”：用HashMap<String, Integer>存储商品名和数量，实现添加商品、删除商品、查看购物车、计算总价功能

- 能编写 “多线程卖票程序”：创建 3 个线程同时卖 100 张票，用 synchronized保证不会出现超卖或重复卖票

- 能编写 “JDBC 学生管理程序”：连接 MySQL 数据库，实现学生信息的添加（insert）、查询（select）、修改（update）、删除（delete）操作

### 自测题 / 实践任务

1. **基础题**：编写程序，使用BufferedReader读取test.txt文件内容（每行是一个整数），计算所有整数的和，若文件不存在或内容非整数，捕获并处理对应异常（FileNotFoundException、NumberFormatException）。

1. **进阶题**：编写 “多线程下载器”（简化版）：创建 2 个线程，分别下载两个不同的图片文件（从指定 URL），使用字节流将图片保存到本地，下载完成后输出 “下载成功”。



# —————————————



# Java 程序设计 知识体系提纲

## 第 3 章 面向对象程序设计（含设计模式与内部类）

### 核心知识点

- 设计模式

- 创建型模式

- 单例模式：饿汉式、懒汉式（线程安全 / 不安全）、静态内部类、双重检查锁定

- 工厂模式：简单工厂、工厂方法、抽象工厂

- 行为型模式

- 策略模式：策略接口、具体策略实现、上下文类

- 回调模式：回调接口定义、调用方注册、被调用方实现

- 代理模式：动态代理（InvocationHandler、Proxy 类）

- 内部类

- 分类：成员内部类、静态嵌套类、局部内部类、匿名内部类

- 特性：访问外部类成员（含私有）、实例依赖关系、访问修饰符支持

- 应用：模拟多继承、事件监听器实现、简化代码结构

### 易混 / 易错概念

1. 单例模式的线程安全问题：未加synchronized的懒汉式在多线程下可能创建多个实例，需通过双重检查锁定（配合volatile）或静态内部类解决

1. 静态嵌套类与成员内部类的区别：静态嵌套类不依赖外部类实例，不能直接访问外部类非静态成员；成员内部类需先创建外部类实例，可访问外部类所有成员

1. 工厂模式的层级混淆：简单工厂（一个工厂类创建所有产品）、工厂方法（一个产品对应一个工厂）、抽象工厂（创建一组相关产品）的适用场景区分不清

1. 动态代理与静态代理的差异：动态代理无需手动编写代理类，通过Proxy动态生成，而静态代理需提前定义代理类实现目标接口

### 前置依赖

1. 面向对象基础：类与对象、继承、接口、多态

1. 基础语法：权限修饰符（private、protected、public）、异常处理基础

1. 反射机制基础（动态代理需用到Class类、Method类）

### 学习目标

1. 能根据场景选择合适的单例模式实现（如饿汉式用于无延迟初始化场景，懒汉式用于资源密集型对象）

1. 能使用策略模式设计可扩展的功能模块（如导航系统的不同出行方式计算）

1. 能区分并实现四种内部类，理解其在实际开发中的应用（如匿名内部类实现监听器）

1. 能通过动态代理为业务方法添加通用功能（如日志记录、事务管理）

### 学习路径

1. 设计模式模块

- 先理解每种模式的 “问题场景→解决方案→代码实现” 逻辑

- 对比相似模式（如简单工厂 vs 工厂方法）的优缺点与适用场景

- 编写小案例验证模式效果（如单例模式的实例唯一性测试、策略模式的动态切换）

1. 内部类模块

- 从成员内部类入手，理解外部类与内部类的实例依赖关系

- 逐步学习静态嵌套类、局部内部类，最后掌握匿名内部类（重点在事件处理中的应用）

- 实践 “内部类模拟多继承” 案例，加深对 Java 不支持多继承的解决方案理解

### 配套资源建议

1. 设计模式：阅读《Head First 设计模式》第 1（策略模式）、5（单例模式）、7（工厂方法）章；B 站搜索 “Java 设计模式 韩顺平” 查看案例讲解

1. 内部类：查阅 Oracle 官方文档《Java Tutorials - Inner Classes》；观看 “尚硅谷 Java 内部类” 教学视频（重点理解实例创建语法）

1. 动态代理：阅读《Java 核心技术卷 I》第 9 章 “反射与代理”；参考 JDK 官方文档中java.lang.reflect.Proxy类的使用说明

### 达成标准

1. 单例模式：能手写四种单例实现，并解释每种实现的线程安全性与优缺点；能通过调试验证实例唯一性

1. 策略模式：能设计 “支付系统”（支持支付宝、微信、银行卡支付），实现支付策略的动态切换，且新增支付方式时不修改原有代码

1. 内部类：能分别用成员内部类、匿名内部类实现 “按钮点击事件监听”，并解释两种实现的代码简化效果

1. 动态代理：能为 “订单服务” 的createOrder、cancelOrder方法添加统一日志记录，无需修改原有业务代码

### 自测题 / 实践任务

1. 自测题：判断以下代码是否为线程安全的单例模式，并说明原因

```
public class Singleton {
    private static Singleton instance;
    private Singleton() {}
    public static Singleton getInstance() {
        if (instance == null) {
            synchronized (Singleton.class) {
                instance = new Singleton();
            }
        }
        return instance;
    }
}
```

（答案：不安全，new Singleton()可能发生指令重排序，需在instance前加volatile修饰）

1. 实践任务：设计一个 “文件解析器”，支持 CSV、Excel、JSON 三种格式解析，要求：

- 使用工厂模式创建不同格式的解析器

- 使用策略模式定义解析逻辑（每种格式对应一个解析策略）

- 新增解析格式时无需修改工厂类与已有解析逻辑

## 第 4 章 GUI 编程（Swing 与 JavaFX）

### 核心知识点

- Java UI 历史与组件库

- AWT：重量级组件，依赖本地系统 UI，组件风格与平台相关

- Swing：轻量级组件，基于 AWT 实现，跨平台一致性好，核心组件（JFrame、JPanel、JButton、JTextField）

- JavaFX：支持富媒体与 WebView，底层使用 DirectX/Metal 渲染，JDK8 官方推荐

- 事件驱动编程

- 事件三要素：事件源（如按钮）、事件对象（如 ActionEvent）、事件处理器（监听器）

- 监听器接口：ActionListener（按钮点击）、MouseListener（鼠标操作）、WindowListener（窗口事件）

- 事件处理流程：注册监听器→触发事件→调用处理器方法

- 布局管理器

- 常用布局：FlowLayout（流式布局）、BorderLayout（边界布局）、GridLayout（网格布局）、GridBagLayout（网格包布局）

- 布局适用场景：如 BorderLayout 用于窗口分区（North/South/Center），GridLayout 用于表格型组件排列

- 适配器类

- 作用：解决监听器接口抽象方法过多的问题（如 WindowListener 有 7 个方法），提供空实现

- 常用适配器：WindowAdapter（窗口事件）、MouseAdapter（鼠标事件）

### 易混 / 易错概念

1. Swing 组件的线程安全问题：Swing 组件非线程安全，必须在事件调度线程（EDT）中创建和更新 UI，直接在主线程操作可能导致界面卡顿或异常

1. 布局管理器的嵌套使用：初学者常忽略 “容器嵌套”（如 JPanel 嵌套在 JFrame 中，各自使用不同布局），导致组件排列混乱

1. 监听器注册与移除：忘记移除监听器（如窗口关闭时未移除 MouseListener）可能导致内存泄漏

1. AWT 与 Swing 的组件混用：如将 AWT 的Button与 Swing 的JButton混用，可能出现风格不一致或事件处理异常

### 前置依赖

1. 基础语法：类的继承、接口实现、匿名内部类

1. 异常处理基础：处理 UI 操作中的 IO 异常（如图片加载失败）

1. 多线程基础：理解事件调度线程（EDT）的作用

### 学习目标

1. 能使用 Swing 创建基础窗口程序（包含按钮、文本框、标签等组件）

1. 能为组件注册监听器，实现交互逻辑（如按钮点击后更新文本框内容）

1. 能根据需求选择合适的布局管理器，实现组件的合理排列

1. 能使用适配器类简化事件处理代码（如用 WindowAdapter 处理窗口关闭事件）

### 学习路径

1. 组件与窗口基础

- 先学习 JFrame 的创建与配置（设置大小、关闭方式、可见性）

- 学习常用组件（JButton、JTextField、JLabel）的创建与添加

- 实践 “Hello World 窗口”：创建一个带按钮和标签的窗口，点击按钮更新标签文本

1. 事件处理

- 理解事件三要素，先实现 ActionListener（按钮点击）

- 逐步学习 MouseListener（鼠标进入 / 退出）、WindowListener（窗口关闭）

- 用匿名内部类简化监听器实现（避免创建过多独立类）

1. 布局管理

- 逐个学习 FlowLayout、BorderLayout、GridLayout，通过小案例验证布局效果

- 实践 “登录窗口”：用 BorderLayout 划分窗口（North 放标题、Center 放表单、South 放按钮），表单区域用 GridLayout 排列标签与文本框

### 配套资源建议

1. Swing 基础：查阅 Oracle 官方文档《The Java Tutorials - Creating a GUI With Swing》；B 站搜索 “Java Swing 入门教程 黑马程序员”

1. 布局管理器：观看 “尚硅谷 Java 布局管理器” 教学视频；参考《Java Swing 完全参考手册》第 5 章

1. JavaFX：阅读 Oracle 官方文档《Getting Started with JavaFX》；学习 OpenJFX 官方示例（如 “HelloWorld”“ColorChooser”）

### 达成标准

1. 窗口创建：能独立创建 JFrame 窗口，设置标题、大小、居中显示，指定关闭方式为 “退出程序”

1. 事件处理：能实现 “计算器 demo”，包含数字按钮与结果文本框，点击按钮将数字追加到文本框

1. 布局管理：能设计 “用户注册窗口”，包含用户名、密码、邮箱输入框及 “注册”“重置” 按钮，组件排列整齐且自适应窗口大小

1. 适配器使用：能使用 WindowAdapter 实现 “窗口关闭时提示确认” 功能，避免直接关闭程序

### 自测题 / 实践任务

1. 自测题：以下代码创建的窗口为何无法显示按钮？如何修改？

```
public class MyFrame extends JFrame {
    public MyFrame() {
        JButton btn = new JButton("Click Me");
        // 未添加按钮到窗口
        setSize(300, 200);
        setVisible(true);
    }
    public static void main(String[] args) {
        new MyFrame();
    }
}
```

（答案：未将按钮添加到窗口的内容面板，需添加this.getContentPane().add(btn);）

1. 实践任务：创建 “石头剪刀布游戏” GUI：

- 窗口包含 “石头”“剪刀”“布” 三个按钮，一个结果标签，一个记录文本域

- 点击按钮后，程序随机生成电脑选择，判断胜负并更新结果标签

- 将每轮对战记录追加到文本域，支持 “重新开始” 和 “退出” 功能

## 第 5 章 异常处理

### 核心知识点

- 异常的概念与分类

- 异常根类：Throwable（包含 Error 与 Exception）

- Error：系统错误（如 OutOfMemoryError），程序无法处理，需通过优化代码或调整环境解决

- Exception：程序可处理的异常

- 受检异常（Checked Exception）：编译期强制处理（如 IOException、SQLException），需用 try-catch 或 throws 声明

- 非受检异常（Unchecked Exception）：运行时异常（如 NullPointerException、ArrayIndexOutOfBoundsException），编译期不强制处理

- 异常处理机制

- try-catch 块：捕获并处理异常，多个 catch 块按异常类型从子类到父类排列

- finally 块：无论是否发生异常都会执行，用于资源释放（如关闭文件流、数据库连接）

- throws/throw：throws 声明方法可能抛出的异常，throw 手动抛出异常对象

- 自定义异常

- 实现方式：继承 Exception（受检异常）或 RuntimeException（非受检异常）

- 核心要素：提供带参构造方法（传递异常信息），可添加自定义属性（如错误码）

### 易混 / 易错概念

1. 受检与非受检异常的区分：初学者常混淆RuntimeException及其子类（非受检）与其他 Exception 子类（受检），导致未正确处理受检异常

1. finally 块的执行时机：误以为 “return 之后 finally 不执行”，实际 return 前会先执行 finally 块（除非遇到System.exit(0)）

1. 异常的嵌套处理：多层方法调用时，异常会向上传播，初学者常忽略 “上层方法需处理或声明下层方法抛出的异常”

1. 自定义异常的继承选择：不清楚何时继承 Exception（需强制处理，如业务异常），何时继承 RuntimeException（无需强制处理，如参数校验异常）

### 前置依赖

1. 基础语法：类的继承、构造方法、方法的声明与调用

1. IO 基础：了解文件操作可能产生的异常（如 FileNotFoundException）

1. 逻辑判断：能通过条件判断触发异常（如参数非法时抛出异常）

### 学习目标

1. 能区分受检异常与非受检异常，掌握各自的处理方式

1. 能使用 try-catch-finally 处理异常，正确释放资源（如文件流、数据库连接）

1. 能通过 throws/throw 声明和抛出异常，理解异常的传播机制

1. 能根据业务需求定义自定义异常（如 “无效半径异常”“余额不足异常”）

### 学习路径

1. 异常分类与概念

- 先理解 Throwable 的继承体系（Error→Exception→RuntimeException）

- 列举常见异常案例（如 NullPointerException、IOException），判断其类型

- 对比受检与非受检异常的编译期与运行期表现

1. 异常处理语法

- 学习 try-catch 块的基本使用，掌握多 catch 块的顺序（子类在前，父类在后）

- 学习 finally 块的作用，实践 “文件流关闭” 案例（无论读写成功与否都关闭流）

- 学习 throws/throw 的使用，理解 “方法声明异常→调用方处理” 的流程

1. 自定义异常

- 先实现简单自定义异常（继承 Exception），添加异常信息构造方法

- 实践 “业务异常” 案例（如银行转账时余额不足抛出 “InsufficientBalanceException”）

- 结合 try-catch 处理自定义异常，返回友好提示

### 配套资源建议

1. 异常基础：阅读《Java 核心技术卷 I》第 7 章 “异常、断言和日志”；B 站搜索 “Java 异常处理 详解”

1. 资源释放：学习 JDK8 的 try-with-resources 语法（自动关闭 AutoCloseable 接口实现类），参考 Oracle 文档《The try-with-resources Statement》

1. 自定义异常：参考《Effective Java》第 10 章 “异常”，理解自定义异常的设计原则

### 达成标准

1. 异常处理：能编写 “文件读取程序”，处理 FileNotFoundException（文件不存在）和 IOException（读取错误），并在 finally 块中关闭文件流

1. throws/throw 使用：能实现 “圆类” 的setRadius方法，当半径为负数时抛出IllegalArgumentException，并在调用方用 try-catch 处理

1. 自定义异常：能定义 “学生成绩异常”（ScoreException），当成绩小于 0 或大于 100 时抛出，在成绩录入程序中捕获并提示 “成绩范围应在 0-100 之间”

1. try-with-resources：能使用 try-with-resources 语法实现 “CSV 文件读取”，无需手动关闭 BufferedReader

### 自测题 / 实践任务

1. 自测题：以下代码的执行结果是什么？为什么？

```
public class FinallyTest {
    public static int getValue() {
        try {
            return 1;
        } catch (Exception e) {
            return 2;
        } finally {
            return 3;
        }
    }
    public static void main(String[] args) {
        System.out.println(getValue());
    }
}
```

（答案：3，因为 finally 块在 return 前执行，finally 中的 return 会覆盖 try/catch 中的 return 值）

1. 实践任务：设计 “银行账户转账程序”，要求：

- 定义自定义异常InsufficientFundsException（余额不足）和InvalidAmountException（转账金额为负）

- 实现transfer方法：接收转账金额，若金额为负抛出InvalidAmountException，若余额不足抛出InsufficientFundsException

- 在主程序中调用transfer，捕获并处理两种异常，输出友好提示

## 第 6 章 文件 IO

### 核心知识点

- File 类

- 功能：操作文件 / 目录属性（判断存在、创建目录、删除文件、获取路径）

- 常用方法：exists()、mkdir()、delete()、getAbsolutePath()、isFile()/isDirectory()

- IO 流分类

- 按操作数据类型：文本 IO（字符流，Reader/Writer）、二进制 IO（字节流，InputStream/OutputStream）

- 按操作方式：节点流（直接操作文件，如 FileReader/FileOutputStream）、处理流（封装节点流，如 BufferedReader/BufferedOutputStream）

- 文本 IO

- 常用类：Scanner（读取文本）、PrintWriter（写入文本）、BufferedReader（缓冲读取，支持readLine()）、BufferedWriter（缓冲写入）

- 编码问题：处理中文时需指定编码（如 UTF-8），避免乱码

- 二进制 IO

- 常用类：FileInputStream/FileOutputStream（文件字节流）、DataInputStream/DataOutputStream（读写基本数据类型）、ObjectInputStream/ObjectOutputStream（对象序列化）

- 对象序列化：需实现Serializable接口（标记接口），transient 关键字修饰的字段不参与序列化

### 易混 / 易错概念

1. 字符流与字节流的选择：初学者常混淆 “文本文件用字符流，非文本文件（图片、视频）用字节流”，误用字节流读取文本导致中文乱码

1. 流的关闭顺序：多个流嵌套时（如 BufferedReader 包装 FileReader），只需关闭外层流（处理流），关闭外层流会自动关闭内层流（节点流）

1. 对象序列化的条件：忘记让类实现Serializable接口，或序列化类的父类未实现该接口，导致NotSerializableException

1. 缓冲流的作用：误以为缓冲流只是 “加快读取速度”，忽略其核心功能（如 BufferedReader 的readLine()读取整行文本，简化文本处理）

### 前置依赖

1. 异常处理：处理 IO 操作中的受检异常（如 FileNotFoundException、IOException）

1. 集合基础：使用 ArrayList 存储从文件读取的数据（如学生信息）

1. 面向对象：理解对象的属性与方法，支持对象序列化

### 学习目标

1. 能使用 File 类操作文件 / 目录（创建目录、判断文件存在、删除文件）

1. 能区分字符流与字节流，根据文件类型选择合适的 IO 流（文本用字符流，非文本用字节流）

1. 能使用文本 IO 读写文本文件（如读取 CSV 文件、写入日志）

1. 能使用二进制 IO 读写非文本文件（如复制图片）和序列化对象（如保存学生列表）

### 学习路径

1. File 类操作

- 先学习 File 类的构造方法（通过路径创建 File 对象）

- 实践 “目录管理”：判断目录是否存在，不存在则创建；遍历目录下的文件

- 学习文件删除与重命名，注意 “删除目录需先删除目录内所有文件”

1. 文本 IO

- 从简单的 Scanner（读取）和 PrintWriter（写入）入手，实践 “读取用户输入并写入文件”

- 学习 BufferedReader/BufferedWriter，对比无缓冲流的效率差异（如读取大文本文件）

- 实践 “CSV 文件读写”：读取学生信息 CSV，排序后写入新 CSV

1. 二进制 IO

- 学习 FileInputStream/FileOutputStream，实践 “图片复制” 案例

- 学习 DataInputStream/DataOutputStream，读写基本数据类型（如 int、double）

- 学习对象序列化，实践 “保存学生列表到文件”，理解Serializable接口与 transient 关键字

### 配套资源建议

1. IO 流基础：阅读《Java 编程思想》第 10 章 “IO 系统”；B 站搜索 “Java IO 流 详解 尚硅谷”

1. 对象序列化：参考 Oracle 文档《Serializing an Object》；观看 “Java 对象序列化 教程”

1. 实战案例：学习 “Apache Commons IO” 工具类（简化 IO 操作），参考官方文档《Commons IO User Guide》

### 达成标准

1. File 类：能编写 “目录清理程序”，删除指定目录下所有后缀为.tmp的临时文件

1. 文本 IO：能读取student.txt（格式：学号，姓名，专业），统计每个专业的学生人数，结果写入major_count.txt

1. 二进制 IO：能实现 “图片压缩工具”（简化版），将图片读取后按指定尺寸写入新文件（非真正压缩，仅调整像素）

1. 对象序列化：能将 ArrayList保存到students.dat，并从该文件读取列表，验证数据一致性

### 自测题 / 实践任务

1. 自测题：以下代码复制图片会出现什么问题？如何修改？

```
public class CopyImage {
    public static void main(String[] args) throws IOException {
        FileReader in = new FileReader("source.jpg");
        FileWriter out = new FileWriter("target.jpg");
        int c;
        while ((c = in.read()) != -1) {
            out.write(c);
        }
        in.close();
        out.close();
    }
}
```

（答案：图片为二进制文件，用字符流（FileReader/FileWriter）读取会导致数据丢失，应改为字节流 FileInputStream/FileOutputStream）

1. 实践任务：设计 “学生信息管理系统（文件版）”，要求：

- 支持新增学生（学号、姓名、专业）并保存到students.dat（序列化）

- 支持读取students.dat中的学生列表，按学号排序后显示

- 支持根据姓名查询学生信息，输出查询结果

- 处理所有 IO 异常，给出友好提示（如文件不存在、读取失败）

## 第 7 章 集合框架

### 核心知识点

- 集合框架概述

- 核心接口：Collection（单列集合）、Map（双列集合，键值对）

- Collection 子接口：List（有序、可重复，如 ArrayList、LinkedList）、Set（无序、不可重复，如 HashSet、TreeSet）

- List 接口实现类

- ArrayList：基于动态数组，查询快（随机访问），增删慢（需移动元素），线程不安全

- LinkedList：基于双向链表，查询慢（需遍历），增删快（仅修改指针），支持队列 / 栈操作

- Vector：线程安全（方法加 synchronized），效率低，已被 ArrayList 替代

- Set 接口实现类

- HashSet：基于哈希表，无序，查询效率高（O (1)），元素需重写hashCode()和equals()

- TreeSet：基于红黑树，有序（自然排序或定制排序），查询效率 O (log n)，元素需实现Comparable或提供Comparator

- Map 接口实现类

- HashMap：基于哈希表，无序，线程不安全，JDK8 后引入红黑树优化哈希冲突

- TreeMap：基于红黑树，键有序，支持按键排序

- Hashtable：线程安全，效率低，键值不能为 null

### 易混 / 易错概念

1. ArrayList 与 LinkedList 的选择：初学者常忽略 “查询频繁用 ArrayList，增删频繁用 LinkedList”，如频繁在列表中间插入元素用 LinkedList 更高效

1. HashSet 的元素去重：忘记重写hashCode()和equals()，导致重复元素无法去重（HashSet 先比较 hashCode，再比较 equals）

1. List 与 Set 的遍历：用 for 循环遍历 LinkedList 效率低（需每次从头遍历），应使用迭代器（Iterator）或增强 for 循环

1. HashMap 的线程安全：在多线程环境下使用 HashMap 可能导致死循环（JDK7 及之前），需使用 ConcurrentHashMap 替代

### 前置依赖

1. 基础语法：泛型（指定集合元素类型，如 ArrayList）、增强 for 循环

1. 面向对象：理解equals()和hashCode()的契约（相等的对象必须有相等的 hashCode）

1. 排序基础：理解自然排序（Comparable）与定制排序（Comparator）

### 学习目标

1. 能根据需求选择合适的集合（如查询频繁用 ArrayList，去重用 HashSet，键值映射用 HashMap）

1. 能熟练使用集合的常用方法（如 List 的add()/get()、Set 的add()/contains()、Map 的put()/get()）

1. 能实现集合元素的排序（自然排序或定制排序，如按学生年龄排序）

1. 能解决集合使用中的常见问题（如 HashSet 去重、HashMap 线程安全）

### 学习路径

1. 集合框架整体认知

- 先理解 Collection 与 Map 的区别（单列 vs 双列）

- 绘制集合框架结构图，明确接口与实现类的继承关系

- 学习集合的通用遍历方式（增强 for 循环、Iterator）

1. List 与 Set

- 先学习 ArrayList，掌握add()/get()/remove()方法，实践 “学生列表管理”

- 学习 LinkedList，对比与 ArrayList 的效率差异，实践 “队列（FIFO）” 实现

- 学习 HashSet，理解去重原理（重写hashCode()和equals()），实践 “去重学生列表”

- 学习 TreeSet，实践 “按成绩排序学生”（实现Comparable接口）

1. Map

- 学习 HashMap，掌握键值对的添加、获取、删除，实践 “学生学号 - 信息映射”

- 学习 TreeMap，实践 “按学号排序输出学生信息”

- 对比 HashMap 与 Hashtable 的区别，了解 ConcurrentHashMap 的线程安全特性

### 配套资源建议

1. 集合基础：阅读《Java 核心技术卷 I》第 9 章 “集合”；B 站搜索 “Java 集合框架 详解 韩顺平”

1. 哈希表原理：观看 “HashMap 工作原理 视频讲解”，理解哈希冲突解决方式（链地址法）

1. 实战优化：参考《Effective Java》第 47 章 “了解和使用集合框架”，学习集合使用的最佳实践

### 达成标准

1. List 操作：能编写 “购物车程序”，支持添加商品、删除商品、修改商品数量、查询商品列表

1. Set 操作：能读取重复的学生姓名列表，用 HashSet 去重后，按字母顺序排序（用 TreeSet）并输出

1. Map 操作：能统计article.txt中每个单词的出现次数，用 HashMap 存储（键：单词，值：次数），结果按次数降序输出

1. 集合排序：能定义Student类（含学号、姓名、成绩），实现Comparable接口按成绩降序排序，用 ArrayList 存储并排序

### 自测题 / 实践任务

1. 自测题：以下代码为何无法实现学生去重？如何修改？

```
class Student {
    private String id;
    private String name;
    // 构造方法、getter、setter
}
public class HashSetTest {
    public static void main(String[] args) {
        Set<Student> set = new HashSet<>();
        set.add(new Student("101", "张三"));
        set.add(new Student("101", "张三"));
        System.out.println(set.size()); // 输出2，期望1
    }
}
```

（答案：Student 类未重写hashCode()和equals()，HashSet 认为两个对象不同。需重写：equals()判断 id 相等则对象相等，hashCode()返回 id 的 hashCode）

1. 实践任务：设计 “单词统计工具”，要求：

- 读取article.txt（英文文本），统计每个单词的出现次数（忽略大小写，排除标点符号）

- 用 HashMap 存储单词 - 次数映射

- 按次数降序排序，次数相同则按单词字母顺序排序，结果输出到word_count.txt

## 第 8 章 多线程编程

### 核心知识点

- 线程基础概念

- 进程与线程：进程是资源分配的基本单位，线程是 CPU 调度的基本单位，线程共享进程资源

- 并发与并行：并发（单 CPU 时间片切换）、并行（多 CPU 同时执行）

- 线程分类：用户线程（默认，需执行完）、守护线程（依赖用户线程，用户线程结束则终止，如 GC 线程）

- 线程创建方式

- 继承 Thread 类：重写run()方法，调用start()启动线程（不可多继承）

- 实现 Runnable 接口：实现run()方法，传入 Thread 构造器（可多实现，推荐）

- 线程池：通过Executors创建（如newFixedThreadPool、newCachedThreadPool），管理线程生命周期，提高效率

- 线程生命周期

- 状态：新建（New）→就绪（Runnable）→运行（Running）→阻塞（Blocked/Waiting/Timed Waiting）→终止（Terminated）

- 状态切换：start()（New→Runnable）、sleep()（Running→Timed Waiting）、wait()（Running→Waiting）、notify()（Waiting→Runnable）

- 线程同步

- 同步问题：多个线程访问共享资源导致数据不一致（如多窗口售票超卖）

- 同步方式：

- synchronized：同步方法 / 同步块，基于对象锁

- ReentrantLock：显式锁，支持公平锁 / 非公平锁，需手动lock()和unlock()

- 死锁：四个必要条件（互斥、请求与保持、不可剥夺、循环等待），需避免

### 易混 / 易错概念

1. start()与run()的区别：直接调用run()方法只是普通方法调用，不会启动新线程；必须调用start()方法，由 JVM 调用run()

1. 线程同步的锁对象：synchronized同步方法的锁对象是this（实例方法）或类对象（静态方法），同步块需显式指定锁对象，初学者常选错锁对象导致同步失效

1. 守护线程的设置时机：必须在start()前调用setDaemon(true)，启动后设置会抛出IllegalThreadStateException

1. 线程池的关闭：shutdown()（等待任务完成后关闭）与shutdownNow()（立即关闭，返回未完成任务）的区别，初学者常误用shutdownNow()导致任务中断

### 前置依赖

1. 面向对象：类的继承、接口实现

1. 异常处理：处理线程相关异常（如 InterruptedException）

1. 基础语法：匿名内部类（用于简化 Runnable 实现）

### 学习目标

1. 能通过两种方式创建线程（继承 Thread、实现 Runnable），理解两种方式的优缺点

1. 能描述线程的生命周期与状态切换，使用sleep()/join()/yield()控制线程

1. 能识别线程安全问题，使用synchronized或 ReentrantLock 实现线程同步

1. 能使用线程池管理线程（如固定大小线程池），理解线程池的优势

### 学习路径

1. 线程基础

- 先理解进程与线程的区别，通过 “多窗口售票” 案例理解线程共享资源的问题

- 学习两种线程创建方式，对比 “继承 Thread（不可多继承）” 与 “实现 Runnable（灵活）” 的差异

- 实践 “多线程输出”：创建 3 个线程，分别输出数字、字母、线程名，观察并发执行效果

1. 线程控制与生命周期

- 学习sleep()（线程休眠）、join()（等待线程结束）、yield()（线程让步），实践 “主线程等待子线程完成”

- 理解线程状态切换，绘制状态切换图，标注触发条件（如sleep()导致 Running→Timed Waiting）

- 学习守护线程，实践 “守护线程随用户线程结束”（如守护线程打印日志，用户线程结束后守护线程终止）

1. 线程同步与线程池

- 分析 “多窗口售票超卖” 问题，理解线程安全的必要性

- 学习synchronized同步方法 / 块，解决售票超卖问题；对比 ReentrantLock（显式锁）的使用

- 学习线程池，实践 “用固定大小线程池执行 10 个任务”，观察线程复用效果

### 配套资源建议

1. 线程基础：阅读《Java 并发编程实战》第 1 章 “并发编程基础”；B 站搜索 “Java 多线程 入门 黑马程序员”

1. 线程同步：观看 “Java synchronized 与 ReentrantLock 区别” 视频；参考 Oracle 文档《Thread Synchronization》

1. 线程池：学习java.util.concurrent包，参考 “Java 线程池 核心参数 详解”

### 达成标准

1. 线程创建：能分别用继承 Thread 和实现 Runnable 的方式，创建两个线程，分别计算 1-100 和 101-200 的和，主线程等待两个线程完成后输出总和

1. 线程控制：能编写 “倒计时程序”，主线程启动一个子线程，子线程从 10 倒数到 0，每 1 秒输出一个数，倒数结束后主线程输出 “时间到！”

1. 线程同步：能实现 “多窗口售票”（100 张票，3 个窗口），使用synchronized确保无超卖、无重复售票

1. 线程池：能使用Executors.newFixedThreadPool(5)创建线程池，提交 10 个 “文件读取任务”（模拟读取不同文件），观察线程池的任务调度

### 自测题 / 实践任务

1. 自测题：以下代码的输出结果是什么？为什么？

```
class MyThread extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
public class ThreadTest {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        t1.run();
        t2.run();
    }
}
```

（答案：输出 1-5 后再输出 1-5，因为直接调用run()方法未启动新线程，而是在主线程中顺序执行 t1 和 t2 的run()方法，需调用start()才会并发执行）

1. 实践任务：设计 “生产者 - 消费者模式”，要求：

- 缓冲区大小为 5，生产者线程不断生产产品（如整数）放入缓冲区，消费者线程不断从缓冲区取出产品

- 使用 ReentrantLock 和 Condition（notFull、notEmpty）实现同步，避免缓冲区满时生产者继续生产，缓冲区空时消费者继续消费

- 生产者每 1 秒生产一个产品，消费者每 2 秒消费一个产品，输出生产和消费的日志（如 “生产者生产：1”“消费者消费：1”）

## 第 9 章 网络编程

### 核心知识点

- 网络基础概念

- URL 与 InetAddress：URL（统一资源定位符，如http://www.sut.edu.cn）、InetAddress（表示 IP 地址，通过域名获取 IP）

- TCP/IP 协议：面向连接、可靠传输（三次握手 / 四次挥手），UDP 协议：无连接、不可靠传输，适用于实时性要求高的场景（如视频通话）

- TCP 编程

- 服务器端：ServerSocket（监听端口，accept()阻塞等待客户端连接）、Socket（与客户端通信）

- 客户端：Socket（连接服务器，指定 IP 和端口）

- 通信流程：服务器启动→监听端口→客户端连接→获取输入输出流→数据传输→关闭连接

- UDP 编程

- DatagramSocket：发送 / 接收数据报的套接字

- DatagramPacket：数据报包（包含数据、目标 IP、端口）

- 通信流程：创建 DatagramSocket→创建 DatagramPacket→发送 / 接收→关闭套接字

- Java RMI

- 远程方法调用：允许一个 JVM 中的对象调用另一个 JVM 中的对象方法

- 核心组件：Stub（客户端代理）、Skeleton（服务器端框架，已废弃）、Registry（注册远程对象）

- 实现步骤：定义远程接口（继承 Remote）→实现远程接口→注册远程对象→客户端查找并调用

### 易混 / 易错概念

1. TCP 与 UDP 的区别：初学者常混淆 “TCP 面向连接（需三次握手）、可靠传输；UDP 无连接、不可靠”，误用 UDP 传输需要可靠的数据（如文件传输）

1. ServerSocket 的accept()方法：该方法是阻塞式的，会暂停线程直到有客户端连接，初学者常忽略 “多线程处理多客户端”，导致服务器只能处理一个客户端

1. 流的关闭顺序：TCP 通信中，需先关闭输出流，再关闭输入流，最后关闭 Socket，否则可能导致数据传输不完整

1. RMI 的远程接口要求：远程接口必须继承Remote，所有方法必须抛出RemoteException，初学者常忘记这些要求导致 RMI 调用失败

### 前置依赖

1. IO 流：理解输入输出流的使用（如 DataInputStream/DataOutputStream 用于 TCP 数据传输）

1. 多线程：掌握多线程基础，支持服务器端多线程处理多客户端

1. 异常处理：处理网络相关异常（如 ConnectException、IOException）

### 学习目标

1. 能使用 InetAddress 类获取域名对应的 IP 地址，解析 URL 的协议、主机、端口等信息

1. 能实现 TCP 客户端与服务器端通信（如客户端发送消息，服务器端接收并回复）

1. 能实现 UDP 数据报的发送与接收（如客户端发送字符串，服务器端接收并打印）

1. 能理解 Java RMI 的原理，实现简单的远程方法调用（如远程计算两个数的和）

### 学习路径

1. 网络基础与 URL/InetAddress

- 先学习 URL 类的常用方法（getProtocol()、getHost()、getPort()），实践 “解析 URL 信息”

- 学习 InetAddress 类，实践 “通过域名获取 IP”（如InetAddress.getByName("[www.baidu.com](http://www.baidu.com)")）

- 理解 TCP 与 UDP 的协议差异，明确适用场景（如文件传输用 TCP，实时聊天用 UDP）

1. TCP 编程

- 先实现简单的 TCP 服务器与客户端：服务器端监听端口，客户端连接后发送 “Hello Server”，服务器端接收并回复 “Hello Client”

- 学习多线程服务器：服务器端通过accept()获取客户端 Socket 后，启动新线程处理通信，支持多客户端同时连接

- 实践 “文件传输”：客户端读取本地文件，通过 TCP 发送给服务器端，服务器端接收并保存文件

1. UDP 编程与 RMI

- 学习 UDP 编程：实现 “广播消息”，客户端发送数据报，服务器端接收并打印

- 学习 Java RMI：按步骤实现 “远程计算器”，定义远程接口Calculator（含add(int a, int b)），实现类CalculatorImpl，注册到 Registry，客户端查找并调用add方法

### 配套资源建议

1. 网络基础：阅读《TCP/IP 详解 卷 1》第 1 章 “概述”；B 站搜索 “TCP/IP 协议 三次握手 四次挥手”

1. TCP/UDP 编程：参考 Oracle 文档《Java Networking and Proxies》；观看 “Java TCP 编程 实战 尚硅谷”

1. RMI：参考 Oracle 文档《Java RMI Tutorial》；观看 “Java RMI 入门教程”

### 达成标准

1. URL/InetAddress：能解析https://www.sut.edu.cn:8080/index.jsp?name=java，输出协议（https）、主机（[www.sut.edu.cn](https://www.sut.edu.cn)）、端口（8080）、文件路径（/index.jsp）

1. TCP 通信：能实现 “多客户端聊天服务器”，服务器端可同时接收多个客户端的消息，并将消息广播给所有客户端（如客户端 A 发送 “大家好”，所有客户端都能收到）

1. UDP 通信：能实现 “实时天气播报”，服务器端每隔 3 秒发送天气数据（如 “北京 25℃ 晴”），多个客户端接收并显示

1. Java RMI：能实现 “远程学生成绩查询”，远程接口提供getScore(String studentId)方法，客户端输入学号，调用远程方法获取成绩并显示

### 自测题 / 实践任务

1. 自测题：以下 TCP 服务器端代码有什么问题？如何修改以支持多客户端？

```
public class TcpServer {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8888);
        while (true) {
            Socket socket = serverSocket.accept();
            // 处理客户端通信（单线程，只能处理一个客户端）
            DataInputStream in = new DataInputStream(socket.getInputStream());
            System.out.println("收到客户端消息：" + in.readUTF());
            socket.close();
        }
    }
}
```

（答案：单线程处理，accept()后在主线程处理客户端通信，无法接收新客户端。需创建新线程处理每个客户端：在accept()后启动new Thread(() -> { // 处理通信 }).start()）

1. 实践任务：设计 “TCP 文件传输工具”，要求：

- 服务器端：监听指定端口，接收客户端发送的文件，保存到本地指定目录，接收完成后回复 “文件接收成功”

- 客户端：选择本地文件，连接服务器端，发送文件名和文件内容，接收服务器端回复并显示

- 处理异常：如文件不存在、服务器连接失败、传输中断，给出友好提示

## 第 10 章 数据库编程

### 核心知识点

- JDBC 基础

- JDBC 概念：Java 数据库连接，提供统一的 API 访问不同数据库（MySQL、Oracle）

- JDBC 架构：应用程序→JDBC API→JDBC 驱动→数据库

- 核心组件：DriverManager（注册驱动、获取连接）、Connection（数据库连接）、Statement（执行 SQL）、ResultSet（结果集）

- 数据库连接与 SQL 执行

- 连接步骤：注册驱动（Class.forName("com.mysql.cj.jdbc.Driver")）→获取连接（DriverManager.getConnection(url, user, password)）→创建 Statement→执行 SQL→处理结果→关闭资源

- Statement 类型：

- Statement：执行静态 SQL，存在 SQL 注入风险

- PreparedStatement：预编译 SQL，参数用?占位，避免 SQL 注入，效率高

- CallableStatement：执行存储过程

- 事务管理

- 事务特性：ACID（原子性、一致性、隔离性、持久性）

- JDBC 事务控制：默认自动提交（autoCommit=true），设置autoCommit=false手动控制，commit()提交，rollback()回滚

- JPA 与 ORM

- JPA：Java 持久化 API，ORM 规范，将 Java 对象映射到数据库表

- 核心概念：实体（Entity）、实体管理器（EntityManager）、持久化上下文

- 常用注解：@Entity（标记实体类）、@Id（主键）、@Table（指定数据库表名）

### 易混 / 易错概念

1. Statement 与 PreparedStatement 的区别：初学者常使用 Statement 执行动态 SQL（如拼接用户输入），导致 SQL 注入风险，应优先使用 PreparedStatement 的参数占位符

1. 数据库连接的关闭顺序：应按 “ResultSet→Statement→Connection” 的顺序关闭，避免资源泄漏，初学者常忽略关闭资源或关闭顺序错误

1. 事务的提交与回滚：忘记设置autoCommit=false，导致 SQL 执行后自动提交，无法回滚；或发生异常时未调用rollback()，导致数据不一致

1. JPA 与 JDBC 的关系：JPA 是 ORM 框架，底层依赖 JDBC，初学者常误以为 JPA 无需了解 JDBC，忽略底层数据交互原理

### 前置依赖

1. SQL 基础：掌握 SELECT/INSERT/UPDATE/DELETE 语句，了解存储过程

1. 面向对象：理解类与对象，支持 JPA 的实体映射

1. 异常处理：处理 JDBC 相关异常（如 SQLException、ClassNotFoundException）

### 学习目标

1. 能使用 JDBC 连接 MySQL 数据库（加载驱动、获取连接）

1. 能使用 PreparedStatement 执行增删改查 SQL，避免 SQL 注入

1. 能使用 JDBC 管理事务（手动提交、回滚），确保数据一致性

1. 能使用 JPA 实现实体映射与数据库操作（保存、查询、删除实体）

### 学习路径

1. JDBC 基础与连接

- 先学习 JDBC 核心组件的作用，理解 “注册驱动→获取连接→执行 SQL→处理结果→关闭资源” 的流程

- 实践 “JDBC 连接 MySQL”：导入 MySQL 驱动包，编写代码注册驱动、获取连接，验证连接成功

- 学习资源关闭的最佳实践：使用 try-with-resources 自动关闭 Connection/Statement/ResultSet

1. SQL 执行与事务

- 学习 Statement 与 PreparedStatement，对比 “静态 SQL 拼接” 与 “参数占位符” 的安全性，实践 “用户登录”（用 PreparedStatement 避免 SQL 注入）

- 学习 ResultSet 的使用，处理查询结果（如遍历学生列表）

- 学习事务管理：实践 “银行转账”，转账过程包含 “扣钱” 和 “加钱” 两个 SQL，设置autoCommit=false，成功则提交，失败则回滚

1. JPA 入门

- 学习 JPA 的 ORM 概念，理解 “实体类→数据库表”“属性→字段” 的映射关系

- 实践 “JPA 实体映射”：定义Student实体类，用@Entity、@Id、@Table注解映射到数据库表

- 学习 EntityManager 的使用，实践 “实体保存与查询”：通过persist()保存学生，find()查询学生

### 配套资源建议

1. JDBC 基础：阅读《Java 数据库编程实战》第 2 章 “JDBC 入门”；B 站搜索 “Java JDBC 连接 MySQL 教程”

1. 事务管理：参考 Oracle 文档《JDBC Transaction Management》；观看 “Java JDBC 事务 详解”

1. JPA：阅读《JPA 实战》第 3 章 “实体与映射”；参考 Spring Data JPA 官方文档（简化 JPA 操作）

### 达成标准

1. JDBC 连接：能独立编写 JDBC 代码连接 MySQL，处理 “驱动类找不到”“连接超时” 等异常

1. SQL 执行：能实现 “学生信息管理”，使用 PreparedStatement 完成：

- 新增学生（INSERT）

- 根据学号查询学生（SELECT）

- 根据专业更新学生信息（UPDATE）

- 根据姓名删除学生（DELETE）

1. 事务管理：能实现 “批量插入学生”，插入 10 个学生，若其中一个插入失败，则所有插入回滚，确保数据库中要么有 10 个学生，要么一个都没有

1. JPA 操作：能定义Book实体类（含 id、name、author、price），用 JPA 完成：

- 保存图书到数据库

- 查询所有图书

- 根据作者查询图书列表

- 删除指定 id 的图书

### 自测题 / 实践任务

1. 自测题：以下代码存在什么安全问题？如何修改？

```
public User login(String username, String password) throws SQLException {
    String sql = "SELECT * FROM user WHERE username='" + username + "' AND password='" + password + "'";
    Statement stmt = conn.createStatement();
    ResultSet rs = stmt.executeQuery(sql);
    if (rs.next()) {
        return new User(rs.getString("username"), rs.getString("password"));
    }
    return null;
}
```

（答案：存在 SQL 注入风险，如输入username=' OR '1'='1，password=' OR '1'='1，SQL 会变为SELECT * FROM user WHERE username='' OR '1'='1' AND password='' OR '1'='1'，查询所有用户。应改为 PreparedStatement：String sql = "SELECT * FROM user WHERE username=? AND password=?";，用pstmt.setString(1, username)和pstmt.setString(2, password)设置参数）

1. 实践任务：设计 “图书管理系统（JDBC 版）”，要求：

- 支持图书的增删改查（新增、查询所有、根据 ISBN 查询、更新价格、删除）

- 使用 PreparedStatement 执行所有 SQL，避免 SQL 注入

- 实现 “批量借书” 功能（一次借多本图书），使用事务确保所有借书操作要么全部成功，要么全部失败（如更新图书库存和用户借阅记录）

- 处理所有异常，输出友好提示（如 “ISBN 不存在”“库存不足”）

## 第 11 章 JavaEE 基础

### 核心知识点

- MVC 架构

- 概念：Model（模型，处理业务逻辑与数据）、View（视图，展示数据）、Controller（控制器，接收请求并分发）

- 作用：解耦业务逻辑、数据与视图，便于维护与扩展

- 实例：JavaEE 中，Model（Service/DAO）、View（JSP/Thymeleaf）、Controller（Servlet/SpringMVC Controller）

- Spring 生态

- Spring：核心是 IoC（控制反转）和 AOP（面向切面编程），管理 Bean 的创建与依赖注入

- SpringMVC：基于 MVC 的 Web 框架，处理 HTTP 请求（Controller 接收请求→Service 处理→View 响应）

- SpringBoot：简化 Spring 配置，自动配置默认环境，快速开发 Web 应用（“约定优于配置”）

- SpringDataJPA：简化数据库操作，基于 JPA 实现，提供 CRUD 接口

- SpringBoot 开发

- 项目结构：src/main/java（Java 代码）、src/main/resources（配置文件、静态资源、模板）

- 核心配置：application.properties（配置端口、数据库连接、JPA 属性）

- 注解使用：@SpringBootApplication（启动类）、@RestController（REST 接口）、@Service（业务层）、@Repository（数据访问层）

### 易混 / 易错概念

1. Spring IoC 与 DI 的关系：IoC（控制反转）是思想，DI（依赖注入）是实现方式，初学者常混淆两者，误以为是两个独立概念

1. SpringMVC 的请求流程：不清楚 “请求→DispatcherServlet→HandlerMapping→Controller→Service→DAO→View” 的流程，导致无法定位请求处理异常

1. SpringBoot 的自动配置：过度依赖自动配置，不理解 “约定优于配置” 的原理，遇到配置冲突时无法解决

1. @Controller 与 @RestController 的区别：@Controller 返回视图，@RestController 返回 JSON（等同于 @Controller+@ResponseBody），初学者常误用导致无法返回预期结果

### 前置依赖

1. JavaSE 基础：面向对象、集合、IO、多线程

1. 数据库与 JDBC：理解数据库连接与 SQL 执行

1. 网络编程基础：理解 HTTP 请求与响应

1. 注解基础：理解 Java 注解的作用（如 @Override、@Deprecated）

### 学习目标

1. 能理解 MVC 架构的思想与作用，描述 Model、View、Controller 的职责

1. 能使用 SpringBoot 创建简单的 Web 应用（如 Hello World 接口）

1. 能使用 SpringMVC 接收 HTTP 请求（GET/POST），处理参数并返回 JSON

1. 能使用 SpringDataJPA 简化数据库操作（如 CRUD）

### 学习路径

1. MVC 与 Spring 基础

- 先学习 MVC 架构，理解 “解耦” 的优势，通过 “用户登录” 案例描述 MVC 各组件的交互（View 提交表单→Controller 接收→Model 验证→View 显示结果）

- 学习 Spring 核心概念：IoC（容器管理 Bean）、DI（自动注入依赖），实践 “Spring Bean 的创建与注入”

- 了解 Spring 生态组件（SpringMVC、SpringBoot、SpringDataJPA）的定位与关系

1. SpringBoot 入门

- 学习 SpringBoot 的优势（简化配置、快速开发），使用 Spring Initializr 创建 SpringBoot 项目（选择 Web、SpringDataJPA、MySQL 依赖）

- 实践 “Hello World 接口”：创建HelloController，用@RestController和@GetMapping定义接口，启动项目并访问

- 学习application.properties配置：配置服务器端口（server.port=8080）、数据库连接（URL、用户名、密码）

1. SpringMVC 与 SpringDataJPA

- 学习 SpringMVC 的请求处理：接收 GET 参数（@RequestParam）、POST 参数（@RequestBody），返回 JSON

- 实践 “用户管理接口”：定义UserController，提供 “新增用户”（POST）、“查询用户”（GET）接口

- 学习 SpringDataJPA：定义UserRepository接口（继承JpaRepository），实践 “通过 Repository 实现 CRUD”（无需编写 SQL）

### 配套资源建议

1. Spring 基础：阅读《Spring 实战》第 1 章 “Spring 之旅”；B 站搜索 “Spring IoC 详解 尚硅谷”

1. SpringBoot：参考 Spring 官方文档《Spring Boot Reference Guide》；观看 “SpringBoot 入门教程 黑马程序员”

1. SpringMVC 与 SpringDataJPA：学习 “SpringMVC 请求流程” 视频；参考 SpringDataJPA 官方文档《Spring Data JPA - Reference Documentation》

### 达成标准

1. MVC 理解：能绘制 “用户查询订单” 的 MVC 交互流程图，标注每个组件的职责（如 View 显示订单列表，Controller 接收用户 ID，Model 查询订单数据）

1. SpringBoot 项目：能使用 Spring Initializr 创建项目，配置数据库连接，启动项目并访问/hello接口，返回 “Hello SpringBoot!”

1. SpringMVC 接口：能实现 “商品管理” REST 接口：

- GET /product/{id}：根据 ID 查询商品

- POST /product：新增商品（接收 JSON 参数）

- PUT /product/{id}：更新商品价格

- DELETE /product/{id}：删除商品

1. SpringDataJPA：能定义Product实体类和ProductRepository接口，通过 Repository 的findById()、save()、deleteById()方法实现商品的 CRUD，无需编写 SQL

### 自测题 / 实践任务

1. 自测题：以下 SpringBoot 代码为何无法返回 JSON 格式的用户列表？如何修改？

```
@Controller
public class UserController {
    @Autowired
    private UserService userService;
    @GetMapping("/users")
    public List<User> getUsers() {
        return userService.findAll();
    }
}
```

（答案：@Controller 默认返回视图，需返回 JSON 需添加@ResponseBody注解，或改为@RestController（等同于 @Controller+@ResponseBody）。修改后：@RestController或@GetMapping("/users")方法添加@ResponseBody）

1. 实践任务：设计 “学生管理系统（SpringBoot 版）”，要求：

- 技术栈：SpringBoot+SpringMVC+SpringDataJPA+MySQL

- 功能：

- 学生列表查询（GET /students，支持分页）

- 学生详情查询（GET /students/{id}）

- 学生新增（POST /students，接收 JSON 参数）

- 学生修改（PUT /students/{id}）

- 学生删除（DELETE /students/{id}）

- 配置：application.properties配置数据库连接、JPA 自动建表（spring.jpa.hibernate.ddl-auto=update）

- 测试：使用 Postman 测试所有接口，确保功能正常