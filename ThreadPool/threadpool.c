

#define LIST_INSERT(item, list) do { \
    if (list != NULL) list->prev = item; \
    item->prev = NULL; \
    item->next = list; \
    list = item; \
} while(0)

#define LIST_REMOVE(item, list) do {                      \
    if ((item)->prev != NULL) (item)->prev->next = (item)->next; \
    if ((item)->next != NULL) (item)->next->prev = (item)->prev; \
    if ((list) == (item)) (list) = (item)->next;                 \
    (item)->prev = (item)->next = NULL;                          \
} while(0)



//用来存储执行的任务,关于任务节点的定义
struct nTask{
    //做任务函数
    void (*task_func)(struct nTask *task);
    //每个任务是不一样的,做的每个任务都有不同的方法，传入所做任务的参数不同,做任务所用的参数*user_data
    void *user_data;

    //以链表形式来存储任务队列
    struct nTask *prev;
    struct nTask *next;
}

//关于任务的执行
struct nWorker{
    pthread_t threadid;
    struct nManager *manager;//柜员的上级部门，大堂经理
    struct nWorker *prev;
    struct nWorker *next;
};


//管理组件，管理执行和任务,实际上就是线程池，typedef为ThreadPool
typedef struct nManager{
    struct nTask *tasks;//指向任务队列的首节点
    struct nWorker *nWorkers;//指向执行队列的首节点

    pthread_mutex_t mutex;//锁
    //若柜员没有任务可执行，要进行等待,引入条件变量
    pthread_cond_t cond;

}ThreadPool;

//线程回调函数
static *nThreadPoolCallBack(void *arg){
    //线程就是一直在等待任务队列中是否有任务
    struct nWorkers *worker = (struct nWorkers*)arg;
    printf("nThreadPoolCallback\n");
    while(1){
        pthread_mutex_lock(&worker->manager->mutex);
        while(worker->manager->tasks == NULL){//营业员要去判断这个任务队列里面有没有任务，使用NULL来判断
            if(worker->terminate) break;
            pthread_cond_wait(&worker->manager->cond,&worker->manager->mutex);//若没有任务，一直处于阻塞等待状态
        }
        //当worker的terminate=1时候，就会退出
        if (worker->terminate)
        {   
            pthread_mutex_unlock(&worker->manager->mutex);
            break;
        }
        
        //判断任务队列有任务，就要拿出任务出来,这里是把首节点拿出来
        struct nTask *task = worker->manager->tasks;
        LIST_REMOVE(task,worker->manager->tasks);

        pthread_mutex_unlock(&worker->manager->mutex);
        //任务开始执行：
        task->task_func(task->user_data);
    }

    free(worker);


}
//在写组件的时候：首先是定义它的属性、结构，接着就是定义方法
//创建一个线程池、对线程池初始化
int nThreadPoolCreate(ThreadPool *pool, int numWorkers){//numWorker就是多少种方法
    //参数的校验
    if(pool == NULL) return -1;
    if(nWorker < 1) nWorker = 1;
    memset(pool,0,sizeof(ThreadPool));
        //初始化
    pthread_cond_t blank_cond = PTHREAD_COND_INITALIZER;//定义一个空白的锁
    memcpy(&pool->cond,&blank_cond,sizeof(pthread_cond_t));

    //mutex初始化
    pthread_mutex_init(&pool->mutex,NULL);

    //关于nworkers初始化，比如初始化10个线程
    int i = 0;
    for(i = 0; i < numWorkers; i++){
        struct nWorker *worker = (struct nWorker*)malloc(sizeof(struct nWorker));
        if(worker == NULL){
            perror("malloc");
            return -2;
        }
        //每创建一个，加入到工作队列中
        memset(worker,0,sizeof(struct nWorker));
        worker->manager = pool;//

        int ret = pthread_create(worker->threadid,NULL,nThreadPoolCallBack,worker);
        if(ret){//如果创建失败
            perror("pthread_create");
            free(worker);;
            return -3;
        }
        //将创建好的添加到执行队列中去
        LIST_INSERT(worker,pool->nWorkers);

    }

    //success
    return 0;
    
}
//线程池销毁
int nThreadPoolDestory(ThreadPool *pool, int nWorker){
    struct nWorker *worker = NULL;

    for(worker = pool->workers;worker != NULL;worker=worker->next){
        worker->terminate;
    }
    //做一个条件广播
    pthread_mutex_lock(&pool->mutex);//这把锁和在条件等待时候是同一把锁,所以不会出现死锁
    pthread_cond_broadcast(&pool->cond);
    pthread_mutex_unlock(&pool->mutex);

    pool->workers=NULL;
    pool->tasks=NULL;

    return 0;
    //
}
 
//往线程池中push一个任务
int nThreadPoolPushTask(ThreadPool *pool, struct nTask *task){

    pthread_mutex_lock(&pool->mutex);

    LIST_INSERT(task,pool->tasks);

    pthread_cond_signal(&pool->cond);

    pthread_mutex_unlock(&pool->mutex);
}
#if 1

#define THREADPOOL_INIT_COUNT 20
#define TASK_INIT_SIZE 1000

void task_entry(struct nTask *task){ //type
    //struct nTask *task =(struct nTask*)task;
    int idx = *(int *)task->user_data;

    printf("idx:%d\n",idx);

    free(task->user_data);
    free(task);

}

int main(void)
{
    ThreadPool pool = {0};

    nThreadPoolCreate(&pool,THREADPOOL_INIT_COUNT);
    printf("nThreadPoolCreate --- finish");

    int i = 0;

    for(i=0;i<TASK_INIT_SIZE;i++)
    {
        struct nTask *task = (struct nTask *)malloc(sizeof(struct nTask));
        if(task == NULL){
            perror("malloc");
            exit(1);

        }
        memset(task,0,sizeof(struct nTask));

        task->task_func = task_entry;
        task->user_data = malloc(sizeof(int));
        *(int*)task->user_data = i;

        nThreadPoolPushTask(&pool,task);    
    }

    getchar();
}   

#endif

/*
通过gdb调试了三个问题，b，r，c
1. pool没有进行memset，存在脏数据
2. 所传入的void *arg的类型不对导致段错误，改为传入struct nTask *task
3. 主线程没有等待任务的结束。getchar()

*/