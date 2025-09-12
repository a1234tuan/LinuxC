# MySQL数据库配置

好的，这篇指南将详细引导您如何在Linux Ubuntu系统上安装MySQL服务器，并完成一系列关键的初始配置，包括安全设置、用户创建和远程连接配置。

本教程适用于 Ubuntu 20.04, 22.04 及更高版本。

### 第一步：更新系统软件包



在安装任何新软件之前，都应该先更新您服务器的软件包列表，以确保获取到最新的版本和安全补丁。

打开终端，执行以下命令：

Bash

```
sudo apt update
sudo apt upgrade
```



### 第二步：安装MySQL服务器



Ubuntu的默认软件库中包含了MySQL，可以直接使用 `apt` 命令进行安装。

```bash
sudo apt install mysql-server
```

安装过程中，系统会自动处理所有依赖项。安装完成后，MySQL服务通常会自动启动。

您可以检查MySQL服务的状态来确认它是否正在运行：

```bash
sudo systemctl status mysql
```

如果看到 `active (running)` 的字样，说明MySQL已经成功安装并正在运行。按 `q` 键退出状态查看。



### 第三步：运行安全配置脚本



新安装的MySQL存在一些默认的不安全设置（例如，匿名用户、允许root远程登录等）。MySQL提供了一个交互式的安全脚本 `mysql_secure_installation` 来帮助我们快速修复这些问题。

运行以下命令启动脚本：

```bash
sudo mysql_secure_installation
```

接下来，您将看到一系列的提问。以下是建议的配置：

1. **VALIDATE PASSWORD COMPONENT? (是否启用密码验证组件?)**
   - 这个组件会要求用户设置符合特定复杂度的密码。为了服务器安全，**建议启用**。
   - 输入 `Y` 并回车。
   - 接下来选择密码验证策略的级别，`MEDIUM` (中) 通常是比较好的选择，要求密码包含数字、大小写字母、特殊字符和一定的长度。输入 `1` 并回车。
2. **Please set the password for root... (为root用户设置密码)**
   - 在这里为MySQL的 `root` 管理员用户设置一个**强密码**。输入两次以确认。
   - **重要提示**: 请务必记住这个密码！
3. **Remove anonymous users? (移除匿名用户?)**
   - 匿名用户会带来安全风险。**强烈建议移除**。
   - 输入 `Y` 并回车。
4. **Disallow root login remotely? (禁止root用户远程登录?)**
   - 这是非常重要的安全措施。您应该为应用程序创建专用的用户，而不是使用root账户进行远程连接。**强烈建议禁止**。
   - 输入 `Y` 并回车。
5. **Remove test database and access to it? (移除test数据库及其权限?)**
   - 这个数据库仅用于测试，生产环境中不需要。**建议移除**。
   - 输入 `Y` 并回车。
6. **Reload privilege tables now? (现在重新加载权限表?)**
   - 为了让以上所有更改立即生效，需要重新加载权限表。
   - 输入 `Y` 并回车。

完成以上步骤后，您的MySQL安装就变得安全多了。



### 第四步：管理MySQL服务



您可以使用 `systemctl` 来管理MySQL服务，以下是常用命令：

- **检查状态**:

  

  ```bash
  sudo systemctl status mysql
  ```

- **停止服务**:

  ```bash
  sudo systemctl stop mysql
  ```

- **启动服务**:

  ```bash
  sudo systemctl start mysql
  ```

- **重启服务** (在修改配置文件后常用):

  ```bash
  sudo systemctl restart mysql
  ```

- **设置开机自启** (默认已启用):

  ```bash
  sudo systemctl enable mysql
  ```

- **禁止开机自启**:

  ```bash
  sudo systemctl disable mysql
  ```



### 第五步：登录MySQL及创建新用户



在Ubuntu上，默认的MySQL `root` 用户使用 `auth_socket` 插件进行身份验证，这意味着您需要使用 `sudo` 权限才能登录，而无需输入密码。



#### 登录MySQL Shell

```bash
sudo mysql
```

成功后，您将看到 `mysql>` 提示符。



#### 创建新的数据库和用户（推荐实践）



在实际应用中，不推荐直接使用 `root` 用户。最佳实践是为您的每一个应用程序创建专用的数据库和用户。

假设我们要创建一个名为 `myapp_db` 的数据库和一个名为 `myapp_user` 的用户，并授予该用户管理该数据库的所有权限。

在 `mysql>` 提示符下，依次执行以下SQL命令：

1. **创建数据库**:

   ```sql
   CREATE DATABASE myapp_db;
   ```

2. **创建新用户并设置密码**:

   - 将 `your_strong_password` 替换为您自己的安全密码。

   SQL

   ```sql
   CREATE USER 'myapp_user'@'localhost' IDENTIFIED BY 'your_strong_password';
   ```

   - 这里的 `'localhost'` 表示这个用户只能从本机连接。如果您需要远程连接，请看第六步。

3. **授予权限**:

   - 将 `myapp_db` 数据库的所有权限授予 `myapp_user`。

   ```sql
   GRANT ALL PRIVILEGES ON myapp_db.* TO 'myapp_user'@'localhost';
   ```

4. **刷新权限使之生效**:

   ```sql
   FLUSH PRIVILEGES;
   ```

5. **退出MySQL Shell**:

   

   ```sql
   EXIT;
   ```

现在，您可以尝试用新创建的用户登录：

```bash
mysql -u myapp_user -p
```

系统会提示您输入密码，输入您刚才为 `myapp_user` 设置的密码即可登录。



### (可选) 第六步：配置允许远程连接



默认情况下，MySQL只监听本地地址 `127.0.0.1`，这意味着它拒绝所有外部连接。如果您需要从其他服务器连接到此数据库，请按照以下步骤操作。

**安全警告**：向公网开放数据库会带来极大的安全风险，请确保您的防火墙规则足够严格，并且所有MySQL用户都设置了强密码。

1. **修改MySQL配置文件**

   - 找到MySQL的配置文件。在Ubuntu上，它通常位于 `/etc/mysql/mysql.conf.d/mysqld.cnf`。

   - 使用文本编辑器打开它（例如 `nano`）：

     Bash

     ```
     sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf
     ```

   - 找到 `bind-address` 这一行。

   - 默认值是 `127.0.0.1`。要允许所有IP地址连接，请将其修改为 `0.0.0.0`。

     Ini, TOML

     ```
     # 找到这行
     bind-address            = 127.0.0.1
     
     # 修改为
     bind-address            = 0.0.0.0
     ```

   - 保存文件并退出 (`Ctrl+X`, `Y`, `Enter`)。

2. **重启MySQL服务**

   Bash

   ```
   sudo systemctl restart mysql
   ```

3. **配置防火墙**

   - 如果您的服务器启用了UFW防火墙，您需要允许MySQL的默认端口 `3306` 的流量。

   - 您可以只允许特定IP地址访问，这是更安全的方式：

     Bash

     ```
     # 将 your_other_server_ip 替换为您的应用服务器IP地址
     sudo ufw allow from your_other_server_ip to any port 3306
     ```

   - 或者，如果您想允许任何IP地址访问（**不推荐用于生产环境**）：

     Bash

     ```
     sudo ufw allow 3306
     ```

   - 重新加载防火墙规则：

     Bash

     ```
     sudo ufw reload
     ```

4. **为远程用户授权**

   - 您还需要创建一个可以从远程IP登录的用户，或者修改现有用户的权限。

   - 登录MySQL: `sudo mysql`

   - 例如，允许我们之前创建的 `myapp_user` 从任何IP (`%`) 地址连接：

     SQL

     ```
     GRANT ALL PRIVILEGES ON myapp_db.* TO 'myapp_user'@'%' IDENTIFIED BY 'your_strong_password';
     FLUSH PRIVILEGES;
     EXIT;
     ```

   - `%` 是一个通配符，代表任何主机。为了安全，您也可以将其替换为特定的IP地址，如 `'192.168.1.100'`。

### 总结

至此，您已经在Ubuntu上成功安装了MySQL，完成了基础安全加固，学会了如何管理服务，并且创建了用于开发的新用户和数据库。如果需要，您也配置了远程访问。这是部署任何依赖MySQL的应用程序的关键第一步。