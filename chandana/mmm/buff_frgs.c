#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>


#define ROWS 3
#define UNIQUE_STRING  "*#@+%&"

int MMM_Req[ROWS][2] = {
	{100, 10},
	{500, 5},
	{1000, 5}
};

typedef struct NODE
{	
	int tid;
	int time;
	int flag;
	void *s;
	struct NODE *next;
}node;

typedef struct buffer_header_t
{
	int bsize;
	int *bp;
}buffer_header;

typedef struct buffer_tail_t
{
	char uniq_str[8];
}buffer_tail;

typedef struct hlist_h
{
	node *h;
	int total;
	int allocated;
	int total_allocs;
	int total_frees;
	int maxnum_allbuffs;
}buff_pool;

buff_pool pool[3]={
	{NULL,0,0,0,0,0,0},
	{NULL,0,0,0,0,0,0},
	{NULL,0,0,0,0,0,0}
};
int get_hash_key(int size)
{
	printf("======>in hash key fun<======\n");
	int i;
	for(i = 0; i < ROWS; i++)
	{
		if(size == MMM_Req[i][0])
		{
			printf("--------->hkey returning K: %d\n",i);
			return i;
		}
	}
	return (-1);
}

int add_free_buffer(char *p, int size)
{
	printf("========>in add_free_buffer========>\n");
	printf("---->size is : %d\n", size);
	int k = get_hash_key(size);
	printf("value of k is : %d\n",k);
	node  *temp, *new;
	buffer_header *bh = NULL;
	buffer_tail *bt = NULL;
	new =(node *) p;


	bh =(buffer_header *)( p + sizeof(node)) ;
	bt = (buffer_tail *)(p + sizeof(node) + sizeof(buffer_header) + size);

	new->s =(p + sizeof(node)+sizeof(buffer_header));
	new->flag = 1; 
	new->next = NULL;

	bh->bp =(int *) p;
	bh->bsize = size;

	strcpy(bt->uniq_str, UNIQUE_STRING);

	printf("---->starting node adress p is : %p\n", p);
	printf("----------------------->flag is : %d\n",new->flag);
	printf("----------------------->actual buffer is : %p\n",new->s);
	printf("--------->buffer header : %p\n",bh);
	printf("--------->bh SIZE is : %d\n",	bh->bsize);
	printf("--------->BP==p is : %p\n",	bh->bp);
	printf("--------->actual buffer is : %p\n",new->s);
	printf("--------->tail1 : %p\n",bt);
	printf("--------->tail1 : %s\n",(char *)bt);

	if(pool[k].h == NULL)
	{
		//hlist[k] =(node *) p;
		pool[k].h = (node *)p;
		printf("pool of [%d].h value :%p\n", k, pool[k].h);
		pool[k].total++;

		return 0;
	}

	//TODO: NO need to insert at end, 
	//can be at beginning
	for(temp = pool[k].h; temp->next != NULL; temp = temp->next);

	temp->next =(node *) p;
	pool[k].total++;
	printf("====total====%d\n",pool[k].total);
	return 0;
}
void init_free_pool(char *p, int size, int bcount)
{
	int len = 0, i;
	printf("==============> in init free pool <===========\n");

	for(i = 0; i < bcount; i++)
	{
		add_free_buffer(p + len, size);
		printf("P+LEN is : %p\n", p + len);
		printf("size of buffer header %d\n",sizeof(buffer_header));
		printf("size of buffer tail %d\n",sizeof(buffer_tail));
		printf("size of node %d\n",sizeof(node));

		len = len + size +sizeof(node)+ (sizeof(buffer_header) + sizeof(buffer_tail));
	}

	return;
}

void display()
{
	printf("=============> in display <=============\n");
	node *t;
	int i;
	for(i=0;i<3;i++)
	{
		if(pool[i].h != NULL)
		{
			t=pool[i].h;
			for( ;t!=NULL;t=t->next)
			{
				printf("----->p : %p\n", t->s);
			}
			printf("\n");
		}
	}
}

void mem_init()
{
	printf("===========>in mem_init <============\n");
	int i, size = 0, len = 0;
	char *p;

	for(i = 0; i < ROWS; i++)
	{
		size = size + ((MMM_Req[i][0] + 
					sizeof(buffer_header) +sizeof(node)+
					sizeof(buffer_tail)) * 
				MMM_Req[i][1]);
	}

	printf("size is : %d\n", size);

	p = malloc(size);

	for(i = 0; i < ROWS; i++)
	{
		init_free_pool(p + len, MMM_Req[i][0], MMM_Req[i][1]);
		len = len + ((MMM_Req[i][0] + 
					sizeof(buffer_header) +sizeof(node)+
					sizeof(buffer_tail)) * MMM_Req [i][1]);
	}

	display();
}


void *amalloc(int size)
{
	printf("=======>in amalloc fun<========\n");
	node *temp;
	int hk;
	time_t t1;

	hk = get_hash_key(size);
	pool[hk].allocated++;
	pool[hk].total_allocs++;
	printf("===allocated===%d\n",pool[hk].allocated);
	printf("===total_allocs===%d\n",pool[hk].total_allocs);

	if(pool[hk].allocated >= pool[hk].maxnum_allbuffs)
	{ 
		pool[hk].maxnum_allbuffs = pool[hk].allocated;
	}

	printf("===max allocs===%d\n",pool[hk]. maxnum_allbuffs);

	for(temp = pool[hk].h; temp != NULL; temp = temp->next)
	{
		if(temp->flag == 1)
		{   
			temp->flag = 0;

			temp->tid =(unsigned int) pthread_self() ;

			temp->time = time(&t1); 
			printf("--------------->temp->time : %d \n",temp->time);
			printf("--------------->temp->tid :%u\n",temp->tid);
			printf("--------------->malloc returning = afree p: %p\n",((char
							*)temp+sizeof(buffer_header)+sizeof(node)));
			return ( ((char *)temp) + sizeof(buffer_header)+sizeof(node));
		}
	}
	return NULL;
}

void afree(void *p)
{
	printf("=======>in afree fun<=======\n");
	node *temp;
	buffer_header *bh=NULL;
	buffer_tail *bt=NULL;
	int a,hk;
	//printf(">size of buffer_header is : %d\n",sizeof(buffer_header));
	bh = (buffer_header *)((char *)p - sizeof(buffer_header));
	bt = (buffer_tail *) ((char *)p + (bh->bsize));
	printf("---------------->buffer header  : %p\n",bh);
	printf("---------------->buffer size is : %d\n",bh->bsize);
	printf("---------------->BP buffer is : %p\n",bh->bp);

	temp=(node *)bh->bp;
	printf("---------------->value of P in afree:%p\n",p);

	printf("---------------->starting node address value == BP : %p\n",temp);
	printf(" --------------->bt value tail address: %p\n",bt);
	printf(" --------------->bt : %s\n",(char *)bt);
	printf(" --------------->unique string: %s\n",UNIQUE_STRING);
	a = memcmp(bt, UNIQUE_STRING,7);
	printf("-----a value is : %d\n",a);
	if (a != 0)
	{
		printf(".....>>>>>> over flow occured <<<<<<.....\n");
		printf(" -----> tid  : %u\n", temp->tid);
		printf(" -----> time : %u\n", temp->time);
	}
	printf("before free flag is : %d\n",temp->flag);

	temp->tid =  0;
	temp->time = 0;
	temp->flag = 1;

	printf("buffer size : %d is freeing now \n",bh->bsize);
	hk = get_hash_key(bh->bsize);
	pool[hk].allocated--;
	pool[hk].total_frees++;
	printf("=== total free's===%d\n",pool[hk].total_frees);
	return;
}

void *my_thread1(void *vargp)
{
	printf("=======>mythread fun1<========\n");
	char s[]="Networks";
	printf("size of string : %d\n",sizeof(s));
	//	int* tid = (int *)vargp;
	char *p;
	int i = 0;

	p=amalloc(100);
	printf("Size is: %d\n", 100);
	printf("T1 :%p\n", p);

	while(p == NULL)
	{
		printf("-->T1 asking for buffer for %d times\n", i++);
		sleep(1);
		p=amalloc(100);
		i++;
	}
	printf("-->T1 got for buffer\n");
	printf("-->T1 using buffer\n");
	strcpy(p, s);
	printf("---------->UNIQUE_STRING :%s\n",UNIQUE_STRING );
	printf("-->T1 After using buffer\n");
	//printf("-->T1 going for sleep for 3 sec\n");
	printf("-->T1 going to free buffer adress is : %p\n",p);
	//	p=amalloc(100);
	printf("Size is: %d\n", 100);
	printf("T1 :%p\n", p);
	afree(p);

	p=amalloc(500);
	p=amalloc(500);
	//	printf("Size is : %d\n", 500);
	//	afree(p);
	p=amalloc(1000);
	p=amalloc(100);
	//	printf("Size is: %d\n", 1000);
	//	afree(p);
	return 0;
}

void *my_thread2(void *vargp)
{
	printf("=======>MY THREAD FUN2<========\n");
	char s[]="Networks";
	printf("size of string : %d\n",sizeof(s));
	//	int* tid = (int *)vargp;
	char *p;
	int i = 0;

	//	p=amalloc(100);
	printf("Size is: %d\n", 100);
	//	printf("T1 :%p\n", p);

	while(p == NULL)
	{
		printf("-->T1 asking for buffer for %d times\n", i++);
		sleep(1);
		p=amalloc(100);
		i++;
	}
	printf("-->T1 got for buffer\n");
	printf("-->T1 using buffer\n");
	strcpy(p, s);
	printf("---------->UNIQUE_STRING :%s\n",UNIQUE_STRING );
	printf("-->T1 After using buffer\n");
	//printf("-->T1 going for sleep for 3 sec\n");
	printf("-->T1 going to free buffer adress is : %p\n",p);
	p=amalloc(100);
	printf("Size is: %d\n", 100);
	printf("T1 :%p\n", p);
	afree(p);

	p=amalloc(500);
	p=amalloc(500);
	//	printf("Size is : %d\n", 500);
	//	afree(p);
	p=amalloc(1000);
	p=amalloc(100);
	//	printf("Size is: %d\n", 1000);
	//	afree(p);
	return 0;
}
void *my_thread3(void *vargp)
{
	int i;
	for(i=0;i<ROWS;i++)
	{
		printf("=====>total pool[%d]      =%d\n",i,pool[i].total);
		printf("=====>allocated pool[%d]  =%d\n",i,pool[i].allocated);
		printf("=====>remaing pool[%d]    =%d\n",i,pool[i].total-pool[i].allocated);
		printf(">totalallocated poo[%d]   =%d\n",i,pool[i].total_allocs);
		printf("=====>total free pool[%d] =%d\n",i,pool[i].total_frees);
		printf("=>max allocated pool[%d]  =%d\n",i,pool[i].maxnum_allbuffs);
		if(pool[i].total-2<=pool[i].maxnum_allbuffs)
		{
			printf("=============> BOSS pool[%d]  buffers are  over <============\n",i);
		}
	}
	return 0;
}

int main()
{
	pthread_t tid;
	mem_init();
	//while(1)
	//{
	pthread_create(&tid,NULL,my_thread1,NULL);
	pthread_create(&tid,NULL,my_thread2,NULL);
	sleep(5);
	pthread_create(&tid,NULL,my_thread3,NULL);
	pthread_join(tid,NULL);
	//}
	return 0;

}
