#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int mem_req[][2]={
    {5,   50},
    {10,  100},
    {6,   200},
    {8,   300},
    {4,   500},
    {5,   1024}
};

int add_to_free_pool(char *,int);
void *amalloc(int);
void *thread_function1(void *arg);
void *thread_function2(void *arg);

typedef struct _node
{
    void *fb;
    int flag;
    struct _node *next;
}node;
node *head[5]={NULL};

int init_free_pool()
{
    int total_mem_req = 0, i,j;
    char *p = NULL;

    printf("sizeof(mem_req)/ sizeof(mem_req[0])= %d\n",sizeof(mem_req)/sizeof(mem_req[0]));
    for (i = 0; i < sizeof(mem_req)/sizeof(mem_req[0]); i++)
    {
        printf("-->%d. %d %d\n", i, mem_req[i][0], mem_req[i][1]);
        printf("-- --------------------------------->%d\n",mem_req[i][0]);
        total_mem_req += mem_req[i][0] * (mem_req[i][1] + 4);
          p=malloc(total_mem_req );
          printf("p+++++++++++++ %u\n",p);
          for(j=0;j<mem_req[i][0];j++)
        {
            add_to_free_pool(p, mem_req[i][1]);
            p=p+mem_req[i][1];
        }
    }
}
int add_to_free_pool(char *p, int size)
{
    int i;
    node *new, *temp;
    *(int *)p=size;
    int hashkey;
    new = malloc(sizeof(node));
    new->fb = p;
    new->flag = 1;
    new->next = NULL;
    hashkey = gen_hashkey(size);
    if(head[hashkey] == NULL)

    {
        new->next = NULL;
        head[hashkey] = new;
        return 0 ;
    }
    for(temp = head[hashkey]; temp->next != NULL; temp = temp->next);
    temp->next = new;
    new->next = NULL;
}

void * amalloc(int size)
{
    node  *temp;
    int i, hashkey;
    hashkey = gen_hashkey(size);
    for(i = hashkey; i <5; i++)
    {
        for(temp = head[i]; temp != NULL; temp = temp->next)
        {
            if(temp->flag == 1)
            {

                printf("------>buff %d is  allocated  ",i);
                temp->flag = 0;
                printf("%p\n",(temp->fb)+4);
                return ((temp->fb)+4);
            }
        }
    }
}

int  afree(char *p)
{
    node *temp;
    int hashkey,i,size;
    size=(*((int *)p-1));
    printf("size=%d\n",size);
    hashkey=gen_hashkey(size);
    for(i =hashkey; i<5; i++)
    {
        for(temp=head[i];temp!=NULL;temp=temp->next)
        {
            if(temp->fb== p-4)
            {
                temp->flag=1;
                printf("bufffer %d  is freee\n",i+1);
                return 0;
            }
        }
    }
}

void *thread_function1(void *arg)
{
    for( ; ;)
    {
        char *p1, *p2, *p3,*p4;
        printf("for thread 1");
        p1 = amalloc(54);
        printf(" thread 1 memory allocated\n");
        sleep(2);
        printf("for thread 1");
        p2 = amalloc(104);
        printf(" thread 1 memory allocated\n");
        sleep(3);
        printf("for thread 1");
        p3= amalloc(304);
        printf(" thread 1 memory allocated\n");
        sleep(3);
        printf("for thread 1");
        p4 = amalloc(500);
        printf(" thread 1 memory allocated\n");
        sleep(2);
        printf("->:thread 1 is FREE\n");
        afree(p1);
        sleep(2);
        afree(p2);
        sleep(2);
        afree(p3);
        sleep(3);
        afree(p4);
        sleep(3);

    }
}
#if 0
void *thread_function2(void *arg)
{
    for( ; ;)
    {
        char *p1, *p2, *p3,*p4;

        printf(" thread 2 ");
        p1 = amalloc(130);
        sleep(5);
        printf(" thread 2 ");
        p2 = amalloc(240);
        sleep(5);
        printf(" thread 2 ");
        p3= amalloc(400);
        printf(" thread 2 memory allocated\n");
        sleep(8);
        printf(" thread 2 ");
        p4 = amalloc(50);
        printf(" thread 2 memory allocated\n");
        sleep(2);
        printf("->:thread 2 is FREE\n");
        afree(p1);
        sleep(4);
        afree(p2);
        sleep(3);
        afree(p3);
        sleep(3);
        afree(p4);
        sleep(3);

    }
}
void *thread_function3(void *arg)

{
    node *temp;
    int i;
    for(;;)
    {
        for(i=0;i<=4;i++)
        {
            for(temp=head[i];temp->next!=NULL;temp=temp->next)   
            {
                printf ("buf1 IS %d FREE \n", (temp->flag == 1 ? "    ": "NOT"));
                printf ("buf2 IS %d FREE \n", (temp->flag == 1 ? "    ": "NOT"));
                printf ("buf3 IS %d FREE \n", (temp->flag == 1 ? "    ": "NOT"));
                printf ("buf4 IS %d FREE \n", (temp->flag == 1 ? "    ": "NOT"));
                printf ("buf5 IS %d FREE \n", (temp->flag == 1 ? "    ": "NOT"));

                sleep(1);
            }
        }
    }
}
#endif

int gen_hashkey(int size)
{   
int i;
    for (i = 0; i < sizeof(mem_req)/sizeof(mem_req[0]); i++)
    {
    if(size <=mem_req[i][1])                                      
        return 0;
    else if(size >mem_req[i][1] && size <=mem_req[i][1])
        return 1;   
    else if(size >mem_req[i][1] && size <=mem_req[i][1])
        return 2;   
    else if(size >mem_req[i][1]&& size <=mem_req[i][1])
        return 3;   
    else if(size >mem_req[i][1] && size <=mem_req[i][1])
        return 4;   
    else
        return 5;
        }
}

main()
{
    int res;
    pthread_t a_thread,b_thread,c_thread,d_thread;
    void *thread_result;

    init_free_pool();

    //return 0;

    printf("waiting for thread to finsh \n");
    res = pthread_create(&a_thread,NULL,thread_function1,(void*)NULL);
    //res = pthread_create(&b_thread,NULL,thread_function2,(void*)NULL);     
    //    res = pthread_create(&c_thread,NULL,thread_function3,(void*)NULL);     
    res = pthread_join(a_thread,&thread_result);
    //res = pthread_join(b_thread,&thread_result);
    //    res = pthread_join(c_thread,&thread_result);
    printf("thread joined it returned %s\n",(char*)thread_result);
}
