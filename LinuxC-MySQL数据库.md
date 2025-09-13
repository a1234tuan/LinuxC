# LinuxC-MySQL数据库

- 数据库服务器：
  - 多个数据库：databases
    - 数据表：table

在开发过程中所处的地位：

数据库服务器一般处于另一台服务器上，

db server：数据库服务器

node server：节点服务器 【业务逻辑的实现】

客户端服务器

![image-20250912150227203](pic/C_Mysql_API/MySQL数据库架构图1.png)

# 支持远程连接服务器

1. 打开MySQL的配置文件并修改`bind-address`：

```bash
sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf
```

`bind-address`：此刻是回环地址`127.0.0.1`，只对内部机器使用，内部进程通信时候使用的，需要改为`0.0.0.0`

2. 重启`MySQL`服务

```bash
sudo systemctl restart mysql		
```

3. 允许任何IP地址访问（**不推荐用于生产环境**）：

```
sudo ufw allow 3306
```

4. 重新加载防火墙规则：

```
sudo ufw reload
```

# 我的首次连接配置信息

![image-20250912161739709](pic/C_Mysql_API/MySQLWB配置.png)

通过：

```sql
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'Aa6484594..';
CREATE USER 'root'@'%' IDENTIFIED BY 'Aa6484594..';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
```

设置的`password`：`Aa6484594..`

# 已创建的用户信息

- 首先

- 查看状态：

  ```bash
  sudo systemctl status mysql
  ```

- 以`root`用户登录`MySQL`

```bash
mysql -u root -p
```

- 创建名为`admin`密码为`Aa6484549..`的用户

```mysql
create user 'admin'@'%' identified by '6484594';
```

>- ### `'admin'@'%'`
>
>- `'admin'`：新建用户的用户名叫 **admin**。
>
>- `'@'` 后面的 **`%`**：表示允许该用户从 **任意主机** 远程连接 MySQL。
>
>  - 如果写 `'localhost'`，表示只允许本机登录；
>  - 如果写 `'192.168.1.100'`，表示只允许从该 IP 登录；
>  - `%` 是通配符，表示所有主机都行。
>
>- ### `identified by '6484594'`
>
>  - 指定这个用户的密码是 **6484594**。
>
>  - 之后使用这个用户登录时，命令类似：
>
>    ```
>    mysql -u admin -p -h 服务器IP
>    ```
>
>    然后输入密码 `6484594`。



- 查看所有已经创建的用户和对应的主机限制

  首先切换到`mysql`数据库：`use mysql`

  接着使用

  ```sql
  select Host, User from user;
  ```

  

  # 为创建的用户分配权限	

  - 比如我们刚才使用`create user 'admin'@'%' identified by 'Aa6484594..';`创建的`admin`用户在`Mysql workbench`中执行`use mysql`命令，提示权限不够，此时需要为他授予权限

- 分配权限步骤：

1. 先使用`root`用户登录：`mysql -uroot -p`
2. 比如让 `admin` 用户能够管理所有数据库中所有表：

```sql
grant all privileges on *.* to 'admin'@'%';
```

3. 之后还需要刷新一下权限：

```sql
flush privileges;
```





# C API上操作MySQL数据库

![image-20250912181919466](pic/C_Mysql_API/MySQL数据库架构图3.png)

## 数据库建模

对数据库进行数据存储时候，需要预先进行数据库服务器上面建模，创建相应的数据表格：

也就是**数据库建模**

1. 以`root`用户登录`MySQL`：

2. 先创建数据库：`CREATE DATABASE KING_DB;`

3. 进入该数据库：`USE KING_DB;`

4. 创建数据表：`TBL_USER`

```mysql
CREATE TABLE TBL_USER (
    U_ID INT PRIMARY KEY AUTO_INCREMENT,
    U_NAME VARCHAR(32),
    U_GENDER VARCHAR(8)
);

```

5. 显示：`SHOW TABLES;`

## 编写C代码来操作数据库（上）——MySQL C API 程序编译问题排查解决指南

### 遇到的问题描述：

我目前在`vmvare workstation`中创建的`ubuntu`中安装了`mysql`并完成了一系列基础配置，并创建了用户：`admin`、密码：`Aa6484594..`、该数据库所处虚拟机IP：`192.168.17.129`，能够通过`windows`上的`MySQL WorkBench`远程连接该数据库，并且能够正常执行插入、建表等功能。我想通过编写C代码来远程连接数据库进行相应操作，但是出现了问题：我首先通过在虚拟机中创建share共享文件夹，并通过`samba`与`windows`进行文件共享传输，在`windows`上打开由虚拟机创建的`mysql.c`文件，并输入如下代码后，再在ubuntu执行：
```bash
gcc -o mysql mysql.c -I /usr/include/mysql/ -lmysqlclient提示： "mysql.c:2:9: fatal error: mysql.h: No such file or directory
    2 | #include<mysql.h>
      |         ^~~~~~~~~
```

其中`mysql.c`中代码如下：

```c
#include<stdio.h>
#include<mysql.h>
#include<string.h>
#define KING_DB_SERVER_IP "192.168.17.129"
#define KING_DB_SERVER_PORT 3306
#define KING_DB_USERNAME "admin"
#define KING_DB_PASSWORD "Aa6484594.."
#define KING_DB_DEFAULTDB "KING_DB"

#define SQL_INSERT_TBL_USER "INSERT INTO TBL_USER(U_NAME,U_GENDER)VALUES('King','man');"
int main(){
    MYSQL mysql;
    
    if(NULL == mysql_init(&mysql)){
        printf("mysql_init:%s\n",mysql_error(&mysql));
        return -1;

    }


    if(!mysql_real_connect(&mysql, KING_DB_SERVER_IP, KING_DB_USERNAME, KING_DB_PASSWORD
    ,KING_DB_DEFAULTDB,KING_DB_SERVER_PORT,NULL,0)){
        
        printf("mysql_real_connect:%s\n",mysql_error(&mysql));
        return -2; 
    }

    if(mysql_real_query(&mysql,SQL_INSERT_TBL_USER, strlen(SQL_INSERT_TBL_USER))){
        printf("mysql_real_query:%s\n",mysql_error(&mysql));
    }

    mysql_close(&mysql);
    return 0;
    
}

```

### 解决方案

需要先在 Ubuntu 虚拟机中安装 MySQL 客户端开发库。在终端中执行以下命令：

```bash
sudo apt-get update
sudo apt-get install libmysqlclient-dev
```

`libmysqlclient-dev` 包包含了开发 MySQL C 应用程序所需的头文件和库文件。安装完成后，头文件 `mysql.h` 会被放置在 `/usr/include/mysql/` 目录下。

------



### **重新编译 C 代码**



安装完成后，请在 Ubuntu 虚拟机中再次尝试编译您的 C 代码。 `gcc` 命令基本正确，但为了确保链接到正确的库文件，您可以尝试以下命令：

```bash
gcc -o mysql mysql.c $(mysql_config --cflags) $(mysql_config --libs)
```

>- 在大多数情况下，编译任何基于 `MySQL C API`的程序，都可以使用：
>
>  `gcc -o mysql mysql.c $(mysql_config --cflags) $(mysql_config --libs)`
>
>  - `$(mysql_config --cflags)` 会自动告诉编译器 **mysql.h 的头文件路径**
>
>  - `$(mysql_config --libs)` 会自动告诉链接器 **libmysqlclient 库的位置和依赖库**

接着重新执行可执行C文件

```bash
./mysql
```

### 📌 补充说明

1. **如果程序有多个源文件**
    例如你写了 `main.c` 和 `db_utils.c`，就需要：

   ```bash
   gcc -o myprog main.c db_utils.c $(mysql_config --cflags) $(mysql_config --libs)
   ```

2. **如果要写 Makefile**
    通常会写成：

   ```makefile
   CFLAGS  = $(shell mysql_config --cflags)
   LDFLAGS = $(shell mysql_config --libs)
   
   all: mysql_app
   
   mysql_app: mysql.c
       gcc -o mysql_app mysql.c $(CFLAGS) $(LDFLAGS)
   ```

   这样以后只要 `make` 就能编译。

3. **如果使用 CMake**
    也可以通过 `find_package(MySQL)` 或 `mysql_config` 来配置编译选项。

### 总结

1. **初始化**

   - `mysql_init()` → 像给手机装电池，才能用。
   - 一定要先做，不然没法连接。

2. **连接数据库**

   - `mysql_real_connect()` → 真正拨号上网。
   - 参数顺序：`(对象, IP, 用户, 密码, 数据库, 端口, socket, flag)`

   👉 记口诀：**对，IP、账密、库端口，Sock Flag**。

3. **执行 SQL**

   - `mysql_real_query()` → 执行任何 SQL（增删改查）。
   - 注意 SQL 必须符合语法，字符串要传 `strlen()`。

4. **关闭连接**

   - `mysql_close()` → 断开连接。
   - 必须做，不然资源泄漏。

## 在Node Server上写代码操作DB SERVER

### mysql数据库的查询操作：

