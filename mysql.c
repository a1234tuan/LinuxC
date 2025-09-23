#include<stdio.h>        // 标准输入输出库，用于 printf、fopen 等函数
#include<mysql.h>        // MySQL C API 头文件，提供 MySQL 相关操作的函数和结构体
#include<string.h>       // 字符串处理函数库，如 strlen、memset 等

// 数据库连接配置（IP、端口、用户名、密码、默认数据库）
#define KING_DB_SERVER_IP "192.168.17.129"
#define KING_DB_SERVER_PORT 3306
#define KING_DB_USERNAME "admin"
#define KING_DB_PASSWORD "Aa6484594.."
#define KING_DB_DEFAULTDB "KING_DB"

// SQL 语句常量定义
#define SQL_INSERT_TBL_USER "INSERT INTO TBL_USER(U_NAME,U_GENDER)VALUES('test','MAN');"
#define SQL_SELECT_TBL_USER "SELECT * FROM TBL_USER;"   // 查询语句
#define SQL_DELETE_TBL_USER "CALL PROC_DELETE_USER('test')" // 调用存储过程删除用户
#define SQL_INSERT_IMG_USER "INSERT INTO TBL_USER(U_NAME,U_GENDER,U_IMG)VALUES('picname','MAN',?);" // 插入图片（参数 ? 用于绑定 BLOB）
#define SQL_SELECT_IMG_USER "SELECT U_IMG FROM TBL_USER WHERE U_NAME='picname';"                     // 查询图片

#define FILE_IMAGE_LENGTH 64*1024   // 缓冲区大小：64KB（存放图片数据）

//-------------------------------------------
// 功能函数：执行 SELECT 语句并打印结果
//-------------------------------------------
int king_mysql_select(MYSQL *handle){
    // 执行 SQL 查询（发送 SQL 语句给 MySQL 服务器）
    if(mysql_real_query(handle,SQL_SELECT_TBL_USER, strlen(SQL_SELECT_TBL_USER))){
        printf("mysql_real_query:%s\n",mysql_error(handle));
        return -1;
    }

    // 获取查询结果集（结果存储到客户端内存中）
    MYSQL_RES *res = mysql_store_result(handle);
    if(res == NULL){
        printf("mysql_store_result:%s\n",mysql_error(handle));
        return -2;
    }

    // 获取行数
    int rows = mysql_num_rows(res);
    printf("rows:%d\n",rows);
    
    // 获取列数
    int fields = mysql_num_fields(res);
    printf("fields: %d\n",rows);  // 注意：这里打印了 rows，本应打印 fields

    // 遍历结果集，逐行逐列输出
    MYSQL_ROW row;
    while((row = mysql_fetch_row(res))){
        int i = 0;
        for(i = 0 ; i < fields;i++){
            printf("%s\t",row[i]);  // 打印每一列的值
        }
        printf("\n");
    }

    mysql_free_result(res);  // 释放结果集内存
    return 0;
}

//-------------------------------------------
// 从磁盘读取图片文件到内存 buffer
//-------------------------------------------
int read_image(char *filename,char *buffer){
    if(filename == NULL || buffer == NULL)return -1;

    FILE *fp = fopen(filename,"rb");  // 以二进制读模式打开文件
    if(fp == NULL){
        printf("fopen failed\n");
        return -2;
    }

    // 获取文件大小
    fseek(fp,0,SEEK_END);        // 移动到文件末尾
    int length = ftell(fp);      // 获取当前位置（文件大小）
    fseek(fp,0,SEEK_SET);        // 再移动回文件开头

    // 读取文件内容到 buffer
    int size = fread(buffer,1,length,fp);
    if(size != length){
        printf("fread failed:%d\n",size);
        return -3;
    }
    fclose(fp);
    return size;   // 返回文件大小
}

//-------------------------------------------
// 把内存中的图片数据写到磁盘文件
//-------------------------------------------
int write_image(char *filename,char *buffer,int length){
    if(filename == NULL || buffer == NULL || length <= 0)return -1;
    FILE *fp = fopen(filename,"wb+");   // 二进制写模式
    if(fp == NULL){
        printf("fopen failed\n");
        return -2;
    }

    int size = fwrite(buffer,1,length,fp); // 写入文件
    if(size != length){
        printf("fwrite failed: %d\n",size);
        return -3;
    }
    
    fclose(fp);
    return size;
}

//-------------------------------------------
// 向数据库写入图片（二进制大对象 BLOB）
//-------------------------------------------
int mysql_write(MYSQL *handle,char *buffer, int length){
    if(handle == NULL || buffer == NULL || length <=0)return -1;

    MYSQL_STMT *stmt = mysql_stmt_init(handle); // 初始化语句对象
    int ret = mysql_stmt_prepare(stmt,SQL_INSERT_IMG_USER,strlen(SQL_INSERT_IMG_USER)); // 预处理 SQL
    if(ret){
        printf("mysql_stmt_prepare : %s\n",mysql_error(handle));
        return -1;
    }

    // 绑定参数（?）
    MYSQL_BIND param = {0};
    param.buffer_type  = MYSQL_TYPE_LONG_BLOB;  // 参数类型：长 BLOB
    param.buffer = NULL;                        // 数据不直接通过 buffer 传输
    param.is_null = 0;                          // 参数不为 NULL
    param.length = NULL;                        // 长度由 send_long_data 指定

    ret = mysql_stmt_bind_param(stmt, &param);  // 绑定参数
    if (ret) {
        printf("mysql_stmt_bind_param : %s\n", mysql_error(handle));
        return -3;
    }
    
    // 分块发送 BLOB 数据（这里只有一次性发送）
    ret = mysql_stmt_send_long_data(stmt,0,buffer,length);
    if(ret){
        printf("mysql_stmt_send_long_data : %s\n", mysql_error(handle));
        return -4;
    }
    
    // 执行语句
    ret = mysql_stmt_execute(stmt);
    if(ret){
        printf("mysql_stmt_execute : %s\n", mysql_error(handle));
        return -5;
    }

    // 关闭语句句柄
    ret = mysql_stmt_close(stmt);
    if(ret){
        printf("mysql_stmt_close : %s\n", mysql_error(handle));
        return -6;
    }

    return ret;
}

//-------------------------------------------
// 从数据库读取图片（二进制大对象 BLOB）
//-------------------------------------------
int mysql_read(MYSQL *handle,char *buffer,int length){
    if(handle == NULL || buffer == NULL || length <=0)return -1;

    MYSQL_STMT *stmt = mysql_stmt_init(handle); // 初始化语句
    int ret = mysql_stmt_prepare(stmt,SQL_SELECT_IMG_USER,strlen(SQL_SELECT_IMG_USER)); // 预处理查询
    if(ret){
        printf("mysql_stmt_prepare1 : %s\n",mysql_error(handle));
        return -1;
    }

    MYSQL_BIND result = {0};
    result.buffer_type  = MYSQL_TYPE_LONG_BLOB; // 返回类型：长 BLOB
    unsigned long total_length = 0;             // 存储总长度
    result.length = &total_length;              // 把总长度地址传给 MySQL

    ret = mysql_stmt_bind_result(stmt,&result); // 绑定结果集
    if(ret){
        printf("mysql_stmt_bind_result : %s\n",mysql_error(handle));
        return -3;
    }

    ret= mysql_stmt_execute(stmt);  // 执行查询
    if(ret){
        printf("mysql_stmt_execute : %s\n",mysql_error(handle));
        return -4;
    }

    ret = mysql_stmt_store_result(stmt); // 存储结果集到客户端
    if(ret){
        printf("mysql_stmt_store_result: %s\n",mysql_error(handle));
        return -5;
    }

    // 循环获取 BLOB 数据
    while(1){
        ret = mysql_stmt_fetch(stmt);  // 获取一行
        if(ret != 0 && ret != MYSQL_DATA_TRUNCATED){
            break; // 没有更多数据
        }
        
        int start = 0;
        // 分块读取 BLOB 内容
        while (start < (int)total_length) {
            result.buffer = buffer + start;   // 指定写入 buffer 的位置
            result.buffer_length = 1;         // 每次只取 1 字节
            mysql_stmt_fetch_column(stmt, &result, 0, start);
            start += result.buffer_length;
        } 
    }

    mysql_stmt_close(stmt);  // 关闭语句
    return total_length;     // 返回读取的字节数
}

//-------------------------------------------
// 主函数：程序入口
//-------------------------------------------
int main(){
    MYSQL mysql;  // MySQL 连接句柄
    
    // 初始化 MySQL 句柄
    if(NULL == mysql_init(&mysql)){
        printf("mysql_init:%s\n",mysql_error(&mysql));
        return -1;
    }

    // 建立连接
    if(!mysql_real_connect(&mysql, KING_DB_SERVER_IP, KING_DB_USERNAME, KING_DB_PASSWORD,
                           KING_DB_DEFAULTDB,KING_DB_SERVER_PORT,NULL,0)){
        printf("mysql_real_connect:%s\n",mysql_error(&mysql));
        goto Exit;
    }

    // 初始查询
    king_mysql_select(&mysql);

    // 执行插入
    printf("case: mysql --> insert \n");
#if 1
    if(mysql_real_query(&mysql,SQL_INSERT_TBL_USER, strlen(SQL_INSERT_TBL_USER))){
        printf("mysql_real_query1:%s\n",mysql_error(&mysql));
        goto Exit;
    }
#endif

    // 插入后再次查询
    king_mysql_select(&mysql);

    // 执行存储过程删除
    printf("case: mysql --> delete \n");
#if 1
    if(mysql_real_query(&mysql,SQL_DELETE_TBL_USER, strlen(SQL_DELETE_TBL_USER))){
        printf("mysql_real_query2:%s\n",mysql_error(&mysql));
        goto Exit;
    }
#endif

    // 删除后再次查询
    king_mysql_select(&mysql);

    // 插入并读取图片测试
    printf("case: mysql--->read image and write mysql\n");
    char buffer[FILE_IMAGE_LENGTH]= {0};
    int length = read_image("/home/leoking/share/MySQL/test.png",buffer); // 读取本地文件
    if(length < 0)goto Exit;

    mysql_write(&mysql,buffer,length); // 写入数据库

    printf("case: mysql--->read mysql and write image\n");
    memset(buffer ,0 ,FILE_IMAGE_LENGTH);
    length = mysql_read(&mysql,buffer,FILE_IMAGE_LENGTH); // 从数据库读取图片

    write_image("readout.png",buffer,length); // 写到磁盘

Exit:
    mysql_close(&mysql);  // 关闭连接
    return 0;
}
