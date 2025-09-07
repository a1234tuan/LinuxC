/*
要设计通讯录基本架构，首先要解决的是底层数据存储结构，选择链表来链式存储每个联系人【包括姓名、电话号】
然后就功能层面：1.操作底层数据：最底层 包括链表节点的插入、删除操作
2. 接口层：不直接对底层数据操作，而是提供一个接触底层数据结构的接口
新增人：int person_insert 、 删除人：int person_delete 、查找人：struct person* personserch()、遍历：int person_traversal()
3. 接着就是业务层 ：业务层就是通过操作接口层提供的 API 完成面向对用户的服务 


*/
#define NAME_LENGTH 10
#define PHONE_LENGTH 20
#define INFO printf
#define LIST_INSERT(item,list)do{//双向链表存储
    if(list != NULL) list->pre = item;  \
    item->pre = NULL; \
    item->next = list; \
    list = item; 
}while(0)
/*删除节点 B 的整个过程分为:
(1) 更新前驱 A 的 next 
(2) 更新后继 C 的 prev
既需要更新前驱的next又需要更新后继的pre
特殊情况：如果此时B是头结点，则不执行
(3) 清空B自身的指针
*/
#define LIST_DELETE(item,list)do{
    if(item->pre != NULL) item->pre->next = item->next;        \
    if(item->next != NULL) item->next->pre = item->pre;         \
    if ((list) == (item)) (list) = (item)->next;                 \
    (item)->prev = (item)->next = NULL;   
}while(0)
//定义存储类型
struct person{
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    
    struct person* pre;
    struct person* next;
};

struct contacts{
    struct people* person;
    int count;
};

int person_insert(struct person** head, struct person *ps){//要插入的是哪个链表，插入的是哪个节点
    if(ps==NULL) return -1;
    LIST_INSERT(ps,*head);
    *head = ps;
    return 0;
}
int person_delete(struct person** head, struct person *ps){//要删除的是哪个链表中的节点，要删除的具体是哪个节点？     
    if(ps == NULL) return -1;
    LIST_DELETE(ps,*head);
    return 0;
}



int save_file(struct person *people ,const char *filename){
    FILE *fp = fopen(filename,"w");
    if(fp == NULL) return -1;

    struct person *item  = NULL;
    for(item=people;item != NULL;item=item ->next){
        fprint(fp,"name: %s,phone:%s\n",item->name,item->phone);
        fflush(fp);
    }

    fclose(fp);
}
int parser_token(char *buffer,int length,char *name,char *phone){
    if(buffer == NULL) return -1;
    int i = 0,j=0,status=0;
    for(i=0;buffer[i]!=',';i++){
        if(buffer[i] == ' '){
            status = 1;
        }else if(status == 1){
            name[j++]=buffer[i];
        }
    }
    
    status = 0;
    j=0;
    for(;i<length;i++){
        if(buffer[i] == ' '){
            status = 1;
        }else if(status == 1){
            phone[j++]=buffer[i];
        }
    }
}

//9.4
int load_file(struct person **ppeople,int *count,const char *filename){
    FILE *fp = fopen(filename,"r");
    if(fp == NULL) return -1;

    while(!feof(fp)){
        char buffer[BUFFER_LENGTH] = {0};
        fgets(buffer,BUFFER_LENGTH,fp);
        char name[NAME_LENGTH] = {0};
        char phone[PHONE_LENGTH] = {0};

        if(parser_token(buffer,strlen(buffer),name,phone) != 0 ){
            continue;
        }

        struct person *p =(struct person*)malloc(sizeof(struct person));
        if(p==NULL)return -2;
        memcpy(p->name,name,NAME_LENGTH);
        memcpy(p->phone,phone,PHONE_LENGTH);

        person_insert(ppepple,p);
        (*count)++;
    }
    fclose(fp);
    return 0;
}

int save_file(struct person **people, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) return -1;

    struct person *item = NULL;
    for (item = *people; item != NULL; item = item->next) {
        fprintf(fp, "name: %s, phone: %s\n", item->name, item->phone);
        fflush(fp);  
    }
    fclose(fp);
    return 0;
}
                                                    
int save_file(struct person **people, const char *filename)
{
    FILE *fp = fopen(filename,"w");
    if(fp == NULL) return -1;
    
    struct person *item = NULL;
    for()
}

int parser_token(char )
int load_file(struct person **ppeople,const char *filename){

    FILE *fp = fopen(filename,"r");
    if(fp == NULL)return -1;

    while(!feof(fp)){
        char buffer[BUFFER_LENGTH] = {0};
        fgets(buffer,BUFFER_LENGTH,fp);

    }
}

struct person* person_search(struct person* people,const char *name){
    if(name == NULL) return NULL;
    struct person* item = NULL;
    for(item = people ;item != NULL;item = item->next)
    {
        if(!strcmp(name,item->name))
            break;
    }
    return item;
}

int people_traversal(struct person* people){
    struct person* item = NULL;
    for(item = people ;item != NULL;item = item->next)
    {
        print("name: %s /t phone: %s",item->name,item->phone);
    }
    return 0;
}


int insert_entry(struct contacts* cts){
    if(cts == NULL) return -1;
 
    struct person *ps = (struct person*)malloc(sizeof(struct person));
    INFO("请输入要插入的联系人姓名:\n");
    scanf("%s", ps->name);
    INFO("请输入要插入的联系人手机号:\n");
    scanf("%s", ps->phone);

    person_insert(ps,&cts->people);
}

//文件保存与加载的业务层实现
int save_entry(struct contacts *cts){
    if(cts == NULL) return -1;

    INFO("Please Input Save Filename: \n");
    char filename[NAME_LENGTH]={0};
    scanf("%s",filename);

    save_file(cts->people,filename);
}

int load_entry(struct contacts *cts){
    if(cts == NULL) return -1;
    INFO("Please Input Load Filename:\n");
    char filename[NAME_LENGTH]={0};
    scanf("%s",filename);

    load_file(&cts->people,&cts->count,filename);
    
}