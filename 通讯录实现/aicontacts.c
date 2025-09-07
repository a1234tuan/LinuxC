#define NAME_LENGTH 16 
#define PHONE_LENGTH 32
#define INFO printf

#define LIST_INSERT(item,list) do{//没有处理旧头结点的pre
    item->prev = NULL;;
    item->next=list;
    if((list) != NULL) (list)->prev=item;
    (list)=item;
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
    if(list==item) list=item->next;
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

enum{
    OPER_INSERT = 1,
    OPER_PRINT,
    OPER_DELETE,
    OPER_SEARCH,
    OPER_SAVE,
    OPER_LOAD
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

int person_delete(struct person **ppeople,struct person *ps){
    if(ps == NULL) return -1;

    LIST_REMOVE(ps,*ppeople);

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
int person_traversal(struct person *people){
    struct person *item = NULL;
    for(item = people;item != NULL;item = item->next){
        INFO("name: %s,phone: %s\n",item-> name,item->phone);
    }
    return 0;
}

int insert_entry(struct  contacts *cts)
{
    if(cts == NULL) return -1;

    struct  person *p =(struct person*)malloc(sizeof(struct  person));
    if(p= NULL) return -2;

    IFNO("Please Input Name:\n");
    scanf("%s",p->name);

    INFO("Please Input Phone:\n");
    scanf("%s",p->phone);

    if(0 != person_insert(&cts->people,p)){
        free(p);
        return -3;
    }
    
    cts->count++;
    INFO("Insert Succcess\n");

    return 0;

};

int print_entry(struct contacts *cts){
    if(cts == NULL) return -1;
    person_traversal(cts->people);
}

//准备一个name->查找这个名字有没有存在->delete掉
int delete_entry(struct contacts *cts){
    if(cts == NULL)return -1;

    INFO("please Input Name:\n");
    char name[NAME_LENGTH] ={0};

    scanf("%s",name);

    //person
    struct person *ps = person_serach(cts->people,name);
    if(ps==NULL){
        INFO("Person don't Exiest\n");
        return -2;
    }
    //delete
    person_delete(&cts->people,ps);
    free(ps);

    return 0;

}

int search_entry(struct contacts *cts){
    if(cts == NULL)return -1;

    INFO("please Input Name:\n");
    char name[NAME_LENGTH] ={0};

    scanf("%s",name);

    //person
    struct person *ps = person_serach(cts->people,name);
    if(ps==NULL){
        INFO("Person don't Exiest\n");
        return -2;
    }

    INFO("name:%s,phone:%s \n",ps->name,ps->phone);
    return 0;
}

void menu_info(void){
    INFO("\n\n******************************************\n");
    INFO("******1. Add Person\t\t2.Print People*********\n");
    INFO("******3. Del Person\t\t4. Search Person*******\n");
    INFO("******5. Save People\t\t6. Load People********\n");
    INFO("********Other Key for Exiting Program*********\n");
    INFO("\n\n******************************************\n");

}

int main(){
    struct contacts *cts = (struct contacts *)malloc(sizeof(struct contacts));
    if(cts == NULL) return -1;

    memset(cts ,0,sizeof(struct  contacts));

    while (1)
    {
        menu_info();
        int select = 0;
        scanf("%d",  &select);

        switch (select)
        {
        case OPER_INSERT:
            insert_entry(cts);
            break;
        case OPER_PRINT:
            print_entry(cts);
            break;
        case OPER_DELETE:
            delete_entry(cts);
            break;
        case OPER_SEARCH:
            search_entry(cts);
            break;
        case OPER_SAVE:
            break;
        case OPER_LOAD:
            break;
        
    
        }

    }
    
}






