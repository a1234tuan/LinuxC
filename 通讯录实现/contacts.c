#define NAME_LENGTH 16 
#define PHONE_LENGTH 32
#define INFO printf

#define LIST_INSERT(item,list) do{//没有处理旧头结点的pre
    item->prev = NULL;;
    item->next=list;
    list=item;
}while(0)
/***
#define LIST_INSERT(item, list) do { \
    if (list != NULL) list->prev = item; \
    item->prev = NULL; \
    item->next = list; \
    list = item; \
} while(0)
***/
#define LIST_REMOVE(item,list) do{
    if(item->prev != NULL) item->prev->next=item->next;
    if(item->next != NULL) item->next->prev = item->prev;
    if(list==item)list=item->next;
    item->prev=item->next=NULL;
}while(0)

/*// 安全的删除宏
#define LIST_REMOVE(item, list) do {                      \
    if ((item)->prev != NULL) (item)->prev->next = (item)->next; \
    if ((item)->next != NULL) (item)->next->prev = (item)->prev; \
    if ((list) == (item)) (list) = (item)->next;                 \
    (item)->prev = (item)->next = NULL;                          \
} while(0)
 */
struct person{
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    struct person *next;
    struct person *prev;
    //双向链表
};

struct contacts{
    struct person *people;
    int count;
};


//interface
int person_insert(struct person *people,struct person *ps){//这里传入的两个参数有什么区别？ 
    if(ps == NULL) return -1;

    LIST_INSERT(ps,people);

    return 0;
}
/***
int person_insert(struct person **people, struct person *ps) {
    if (ps == NULL) return -1;
    LIST_INSERT(ps, *people); // 解引用得到原链表头
    *people = ps;             // 更新外部链表头
    return 0;
}
***/

int person_delete(struct person *people,struct person *ps){
    if(ps == NULL) return -1;

    LIST_REMOVE(ps,people);

    return 0;
}
/*// 删除（传入链表头的地址）
int person_delete(struct person **people, struct person *ps) {
    if (ps == NULL) return -1;
    LIST_REMOVE(ps, *people); // 更新链表
    free(ps); // 如果需要释放内存
    return 0;
}
*/
struct person* person_search(struct person *people,const char *name){
    
    struct person *item =NULL;
    for(item = people; item != NULL; item = item->next){
        if(!strcmp(name,item->name))
            break;
    }
    return item;
}
int person_traversal(struct person *people,struct person *ps){
    struct person *item = NULL;
    for(item = people;item != NULL;item = item->next){
        INFO("name: %s,phone: %s\n",item-> name,item->phone);
    }
    return 0;
}