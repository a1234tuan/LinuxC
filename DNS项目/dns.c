#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>   // inet_addr 需要这个

// DNS 服务器配置
#define DNS_SERVER_PORT 53
#define DNS_SERVER_IP "114.114.114.114"

// DNS 报文头
struct dns_header {
    unsigned short id;
    unsigned short flags;
    unsigned short questions;
    unsigned short answer;
    unsigned short authority;
    unsigned short additional;
};

// DNS 查询部分
struct dns_question {
    int length;// QNAME 长度
    unsigned short qtype;// 查询类型（1= A 记录）
    unsigned short qclass;// 查询类（1= IN 互联网）
    unsigned char *name;// QNAME 域名部分
};

// 构造 DNS header
int dns_create_header(struct dns_header *header) {
    if (header == NULL) return -1;
    memset(header, 0, sizeof(struct dns_header));
                    
    srandom(time(NULL));
    header->id = (unsigned short)random();  // 随机 ID
    header->flags = htons(0x0100);          // 标志位：标准查询 + 递归
    header->questions = htons(1);           // 1 个问题

    return 0;
}

// 构造 DNS question (hostname: www.baidu.com → 3www5baidu3com0)
int dns_create_question(struct dns_question *question, const char *hostname) {
    if (question == NULL || hostname == NULL) return -1;
    memset(question, 0, sizeof(struct dns_question));

    question->name = (unsigned char*)malloc(strlen(hostname) + 2);
    if (question->name == NULL) {
        return -2;
    }

    question->length = strlen(hostname) + 2;
    question->qtype = htons(1);   // A 记录
    question->qclass = htons(1);  // IN 类

    const char delim[2] = ".";
    unsigned char *qname = question->name;

    // strtok 需要可写字符串，所以复制一份
    char *hostname_dup = strdup(hostname);
    char *token = strtok(hostname_dup, delim);

    while (token != NULL) {
        size_t len = strlen(token);
        *qname = len;
        qname++;
        memcpy(qname, token, len);
        qname += len;
        token = strtok(NULL, delim);
    }
    *qname = 0; // 结尾补 0

    free(hostname_dup);
    return 0;
}

// 打包 DNS 请求
int dns_build_requestion(struct dns_header *header, struct dns_question *question, char *request, int rlen) {
    if (header == NULL || question == NULL || request == NULL) return -1;
    memset(request, 0, rlen);

    int offset = 0;
    memcpy(request + offset, header, sizeof(struct dns_header));
    offset += sizeof(struct dns_header);

    memcpy(request + offset, question->name, question->length);
    offset += question->length;

    memcpy(request + offset, &question->qtype, sizeof(question->qtype));
    offset += sizeof(question->qtype);

    memcpy(request + offset, &question->qclass, sizeof(question->qclass));
    offset += sizeof(question->qclass);

    return offset;
}

// DNS 客户端提交查询
int dns_client_commit(const char *domain) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0); // UDP
    if (sockfd < 0) {
        perror("socket error");
        return -1;
    }

    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(DNS_SERVER_PORT);
    servaddr.sin_addr.s_addr = inet_addr(DNS_SERVER_IP);

    // 构造 header
    struct dns_header header = {0};
    dns_create_header(&header);

    // 构造 question
    struct dns_question question = {0};
    dns_create_question(&question, domain);

    // 构造 request
    char request[1024] = {0};
    int length = dns_build_requestion(&header, &question, request, sizeof(request));

    // 发送请求
    sendto(sockfd, request, length, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

    // 接收响应
    char response[1024] = {0};
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    int n = recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr*)&addr, &addr_len);
    if (n < 0) {
        perror("recvfrom error");
        return -2;
    }

    printf("recvfrom : %d bytes\n", n);
    for (int i = 0; i < n; i++) {
        printf("%02x ", (unsigned char)response[i]);
    }
    printf("\n");

    return n;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <domain>\n", argv[0]);
        return -1;
    }
    dns_client_commit(argv[1]);
    return 0;
}
