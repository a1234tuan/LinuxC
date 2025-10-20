# DNS协议分析

域名 -> IP 域名解析



- ` nslookup www.baidu.com`:查看域名对应`IP`:

```cmd
C:\Users\Administrator>nslookup www.baidu.com
服务器:  ns.sut.edu.cn.sut.edu.cn
Address:  202.199.98.1

非权威应答:
名称:    www.a.shifen.com
Addresses:  110.242.70.57
          110.242.69.21
Aliases:  www.baidu.com
```



## DNS请求头定义与域名查询原则



### **协议报文格式**

![image-20250925124224545](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250925124224545.png)



![image-20250925125357758](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250925125357758.png)

- DNS头包括的六项：

```
struct dns_header{
    unsigned short id;
    unsigned short flags;
    
    unsigned short questions;
    unsigned short answer;

    unsigned short authority;
    unsigned short additional;

};
```

- Queries查询域

![image-20250925130304778](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250925130304778.png)

```
struct dns_question{
	int length;
	unsigned short type;
	unsigned short qclass;
	unsigned char *name;
}
```

**DNS 报文中的 Query**

- 一个 DNS 查询报文（Query）主要包含：
  - **QNAME**：要查询的域名（如 `www.example.com.`）。
  - **QTYPE**：查询类型（A 记录 → IPv4 地址，AAAA → IPv6，MX → 邮件服务器等）。
  - **QCLASS**：通常是 IN（Internet 类）。
- 例如：`QNAME = www.example.com.`, `QTYPE = A`



## DNS header填充与函数实现

```c
int dsn_create_header(struct dns_header *header){
    if(head == NULL)return -1;
    memset(head,0,sizeof(struct header));

    //random
    srandom(time(NULL));
    header->id = random();

    head->flags = htons(0x0100);//转换成统一的网络字节序
    head->questions = 1;
}
```

## DNS question填充与函数实现

```C
// hostname: www.0voice.com
// name: 3www60voice3com0
int dns_create_question(struct dns_question *question,const char *hostname){
        
    if(question == NULL || hostname ==NULL)return -1;
    memset(question, 0 ,sizeof(struct dns_question));

    question->name = (char*)malloc(strlen(hostname)+2);
    if(question->name == NULL){
        return -2;
    }
    
    question->length = strlen(hostname)+2;
    question->qtype= htons(1);
    question->qclass=htons(1);//查询类，通常为1

    //填充到name中
    const char delim[2] = ".";
    char *qname = question->name;

    char *hostname_dum = strdup(hostname);//strdup带有malloc
    char *token = strtok(hostname,delim);//www/.0voice.com，截取规则

    while(token != NULL){
        
        size_t len = strlen(token);

        *qname = len;
        qname++;
        
        strncpy(qname,token,len+1);//可以指定cp长度
        qname += len;

        token = strtok(NULL,delim);//为什么这里指定被截取对象为NULL
        

    }


    free(hostname_dum);

}
```

### DNS协议 UDP编程的实现

>- 通过UDP协议将DNS协议报文发送给DNS服务器
>
>DNS服务器会按照DNS协议返回数据

UDP，基于无连接

connect的作用？保证sendto？

```bash
leoking@ubuntu-server:~/share/DNS$ gcc -o dns dns.c
dns.c: In function ‘dns_create_question’:
dns.c:66:26: warning: passing argument 1 of ‘strtok’ discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
   66 |     char *token = strtok(hostname,delim);//www/.0voice.com，截取规则
      |                          ^~~~~~~~
In file included from dns.c:2:
/usr/include/string.h:356:39: note: expected ‘char * restrict’ but argument is of type ‘const char *’
  356 | extern char *strtok (char *__restrict __s, const char *__restrict __delim)
      |                      ~~~~~~~~~~~~~~~~~^~~
dns.c: In function ‘dns_build_requestion’:
dns.c:95:25: error: ‘rlen’ undeclared (first use in this function)
   95 |     memset(request , 0 ,rlen);
      |                         ^~~~
dns.c:95:25: note: each undeclared identifier is reported only once for each function it appears in
dns.c:100:9: error: redefinition of ‘offset’
  100 |     int offset = sizeof(struct dns_header);
      |         ^~~~~~
dns.c:98:9: note: previous definition of ‘offset’ with type ‘int’
   98 |     int offset = 0;
      |         ^~~~~~
dns.c:106:35: warning: passing argument 2 of ‘memcpy’ makes pointer from integer without a cast [-Wint-conversion]
  106 |     memcpy(request+offset,question->qtype,sizeof(question->qtype));
      |                           ~~~~~~~~^~~~~~~
      |                                   |
      |                                   short unsigned int
/usr/include/string.h:43:70: note: expected ‘const void * restrict’ but argument is of type ‘short unsigned int’
   43 | rn void *memcpy (void *__restrict __dest, const void *__restrict __src,
      |                                           ~~~~~~~~~~~~~~~~~~~~~~~^~~~~

dns.c:109:35: warning: passing argument 2 of ‘memcpy’ makes pointer from integer without a cast [-Wint-conversion]
  109 |     memcpy(request+offset,question->qclass,sizeof(question->qclass));
      |                           ~~~~~~~~^~~~~~~~
      |                                   |
      |                                   short unsigned int
/usr/include/string.h:43:70: note: expected ‘const void * restrict’ but argument is of type ‘short unsigned int’
   43 | rn void *memcpy (void *__restrict __dest, const void *__restrict __src,
      |                                           ~~~~~~~~~~~~~~~~~~~~~~~^~~~~

dns.c: In function ‘dns_client_commit’:
dns.c:127:32: warning: implicit declaration of function ‘inet_addr’ [-Wimplicit-function-declaration]
  127 |     servaddr.sin_addr.s_addr = inet_addr(DNS_SERVER_IP);
      |                                ^~~~~~~~~
dns.c:133:5: warning: implicit declaration of function ‘dns_create_header’; did you mean ‘dsn_create_header’? [-Wimplicit-function-declaration]
  133 |     dns_create_header(&header);
      |     ^~~~~~~~~~~~~~~~~
      |     dsn_create_header
dns.c:136:5: warning: implicit declaration of function ‘dns_create_quesition’; did you mean ‘dns_create_question’? [-Wimplicit-function-declaration]
  136 |     dns_create_quesition(&question,domain);
      |     ^~~~~~~~~~~~~~~~~~~~
      |     dns_create_question
dns.c:140:57: error: ‘reques’ undeclared (first use in this function); did you mean ‘request’?
  140 |     int length = dns_build_requestion(&header,&question,reques,1024);
      |                                                         ^~~~~~
      |                                                         request
dns.c:140:18: error: too many arguments to function ‘dns_build_requestion’
  140 |     int length = dns_build_requestion(&header,&question,reques,1024);
      |                  ^~~~~~~~~~~~~~~~~~~~
dns.c:92:5: note: declared here
   92 | int dns_build_requestion(struct dns_header *header,struct dns_question *question,char *request){
      |     ^~~~~~~~~~~~~~~~~~~~
dns.c:143:44: error: cannot convert to a pointer type
  143 |     sendto(sockfd,request,length,0,(struct sockaddr*)servaddr,sizeof(struct sockaddr));
      |                                            ^~~~~~~~
dns.c:153:9: error: ‘i’ undeclared (first use in this function)
  153 |     for(i = 0;i < n;i++){
      |         ^

```

UDP好处，是tcp不具备的

1. UDP传输速度快。运用场景：下载
2. UDP相应速度快。运用场景：游戏



2. 代码其中的这些code line，其中的函数功能、传入的参数、对应api的语法规则、为什么这样做，以上或多或少都看不懂，请你逐个解析（我这样描述是否合适，请你推测我的核心疑问并作答）

   1. “  srandom(time(NULL));”

   2. header->id = (unsigned short)random();

   3. header->flags = htons(0x0100);

   4. memset(question, 0, sizeof(struct dns_question));

   5.   char *hostname_dup = strdup(hostname);

   6. char *token = strtok(hostname_dup, delim);

   7. int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

   8. struct sockaddr_in servaddr = {0};

        servaddr.sin_family = AF_INET;

        servaddr.sin_port = htons(DNS_SERVER_PORT);

        servaddr.sin_addr.s_addr = inet_addr(DNS_SERVER_IP);

   9.   sendto(sockfd, request, length, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

   10.   socklen_t addr_len = sizeof(addr);

   11.   int n = recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr*)&addr, &addr_len);

