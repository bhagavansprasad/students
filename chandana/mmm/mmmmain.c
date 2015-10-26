
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>


#define UNIQUE_STRING  "*#@+%&"

int MMM_Req[][2] = {
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
	int malloc_missing;
}buff_pool;

buff_pool pool[3]={
	{NULL,0,0,0,0,0,0},
	{NULL,0,0,0,0,0,0},
	{NULL,0,0,0,0,0,0}
};

int get_hash_key(int size)
{
	int i;
	for(i = 0; i < sizeof(MMM_Req)/sizeof(MMM_Req[1]); i++)
	{
		if(size == MMM_Req[i][0])
		{
			printf("hkey returning K: %d\n", i);
			return i;
		}
	}
	return (-1);
}

int add_free_buffer(char *p, int size)
{
	int k = get_hash_key(size);
	//printf("value of k is : %d\n",k);
	node  *temp, *new;
	buffer_header *bh = NULL;
	buffer_tail *bt = NULL;
	new =(node *) p;


	bh =(buffer_header *)( p + sizeof(node)) ;
	bt = (buffer_tail *)(p + sizeof(node) + sizeof(buffer_header) + size);

	new->s =(p + sizeof(node)+sizeof(buffer_header));
	new->flag = 1; 
	new->next = NULL;

	bh->bsize = size;
	bh->bp =(int *) p;

	strcpy(bt->uniq_str, UNIQUE_STRING);

	if(pool[k].h == NULL)
	{
		//hlist[k] =(node *) p;
		pool[k].h = (node *)p;
		pool[k].total++;

		return 0;
	}

	for(temp = pool[k].h; temp->next != NULL; temp = temp->next);

	temp->next =(node *) p;
	pool[k].total++;
	return 0;
}
void init_free_pool(char *p, int size, int bcount)
{
	int len = 0, i;

	for(i = 0; i < bcount; i++)
	{
		add_free_buffer(p + len, size);

		len = len + size +sizeof(node)+ (sizeof(buffer_header) + sizeof(buffer_tail));
	}

	return;
}

void display()
{
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
	int i, size = 0, len = 0;
	char *p;

	for(i = 0; i < sizeof(MMM_Req)/sizeof(MMM_Req[1]); i++)
	{
		size = size + ((MMM_Req[i][0] + 
				sizeof(buffer_header) +sizeof(node) +
				sizeof(buffer_tail)) * 
				MMM_Req[i][1]);
	}

	printf("total size is : %d \n",size);
	p = malloc(size);

	for(i = 0; i < sizeof(MMM_Req)/sizeof(MMM_Req[1]); i++)
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
	node *temp;
	int hk;
	time_t t1;

	hk = get_hash_key(size);


	for(temp = pool[hk].h; temp != NULL; temp = temp->next)
	{
		if(temp->flag == 1)
		{   
			temp->flag = 0;
			pool[hk].allocated++;
			pool[hk].total_allocs++;
			if(pool[hk].allocated >=pool[hk].maxnum_allbuffs)
				pool[hk].maxnum_allbuffs = pool[hk].allocated;

			temp->tid =(unsigned int) pthread_self() ;

			temp->time = time(&t1);
			printf("TID is : %u\n ", temp->tid);
			printf("TIME is : %d\n ",temp->time);
			printf("malloc returning adress is : %p\n",((char*)temp+sizeof(buffer_header)+sizeof(node)));
			printf("=====> end of amalloc function with valid return <=====\n");

			return ( ((char *)temp) + sizeof(buffer_header)+sizeof(node));
		}
	}
	pool[hk].malloc_missing++;

	return NULL;
}

void afree(void *p)
{
	node *temp;
	buffer_header *bh=NULL;
	buffer_tail *bt=NULL;
	int a,hk;
	bh = (buffer_header *)((char *)p - sizeof(buffer_header));
	bt = (buffer_tail *) ((char *)p + (bh->bsize));
	temp=(node *)bh->bp;
	printf("buffer string after use is : %s\n",(char *)bt);
	printf("UNIQUE_string is : %s\n",UNIQUE_STRING);
	a = memcmp(bt, UNIQUE_STRING,7);
	if (a != 0)
	{
		printf(".....>>>>>> over flow occured <<<<<<.....\n");
		printf(" -----> tid  : %u\n", temp->tid);
		printf(" -----> time : %u\n", temp->time);
	}

	temp->tid =  0;
	temp->time = 0;
	temp->flag = 1;

	printf("buffer size : %d is freeing now \n",bh->bsize);
	hk = get_hash_key(bh->bsize);
	pool[hk].allocated--;
	pool[hk].total_frees++;
	return;
}

void *my_thread1(void *vargp)
{
	printf("=======>MY THREAD FUN1<========\n");
	char s[]="Networks";
	char *p;
	int i = 1;
	printf("thread 1 is going for 100 size buffer\n");
	p = amalloc(100);
	printf("T1 :%p\n", p);

	while(p == NULL)
	{
		printf("-->T1 asking for buffer for %d times\n", i);
		//sleep(1);
		p=amalloc(100);
		i++;
	}
	printf("-->T1 got for buffer\n");
	printf("-->T1 using buffer\n");
	strcpy(p, s);
	printf("-->T1 After using buffer\n");
	printf("-->T1 going to free buffer adress is : %p\n",p);
	sleep(30);
	p=amalloc(100);

	printf("thread 1 is going for 500 size buffer\n");
	p=amalloc(500);
	printf("thread 1 is going for 500 size buffer\n");
	p=amalloc(500);
	//	afree(p);
	printf("thread 1 is going for 1000 size buffer\n");
	p=amalloc(1000);
	printf("thread 1 is going for 100 size buffer\n");
	//	afree(p);
	printf("=====> end of my thread fun1 <======\n");
	return 0;
}

void *my_thread2(void *vargp)
{
	printf("=======>MY THREAD FUN2<========\n");
	char s[]="Networks";
	char *p;
	int i = 0;

	printf("thread 1 is going for 100 size buffer\n");
	p=amalloc(100);
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
	printf("-->T1 After using buffer\n");
	printf("-->T1 going to free buffer adress is : %p\n",p);
	//printf("thread 1 is going for 100 size buffer\n");
   	afree(p);

	printf("thread 1 is going for 500 size buffer\n");
	p=amalloc(500);
	printf("thread 1 is going for 500 size buffer\n");
	p=amalloc(500);
	//	afree(p);
	printf("thread 1 is going for 1000 size buffer\n");
	p=amalloc(1000);
	printf("thread 1 is going for 100 size buffer\n");
	p=amalloc(100);
	//	afree(p);
	printf("=====> end of mythread2 function <=====\n");
	return 0;
}
void check_mem_leak()
{
	time_t t1;
	node *temp;
	int tnew=time(&t1),i;
	printf("time is : %u\n",tnew);
	for(i = 0; i < sizeof(MMM_Req)/sizeof(MMM_Req[1]); i++)
	{

		for(temp = pool[i].h; temp != NULL; temp = temp->next)
		{
			if(temp->flag == 0)
			{ 
			printf("temp time is : %u\n",temp->time);
				if(tnew - temp->time > 3)
				{
					printf("memory leak occure in thread id is : %u\n",temp->tid);
					temp->flag = 1;
				}
			}
		}
	}
}
void *my_thread3(void *vargp)
{
	printf("=====> in mythread3 function <=====\n");
	int i;
	printf(" rows %ld\n",sizeof(MMM_Req)/sizeof(MMM_Req[1]));
	for(i = 0; i < sizeof(MMM_Req)/sizeof(MMM_Req[1]); i++)
	{ 
        
		printf("pool[%d]total          : %d\n ",i,pool[i].total);
		printf("pool[%d]allocated      : %d\n ",i,pool[i].allocated);
		printf("pool[%d]total_alloc    : %d\n ",i,pool[i].total_allocs);
		printf("pool[%d]total_frees    : %d\n ",i,pool[i].total_frees);
		printf("pool[%d]maxnum_total   : %d\n ",i,pool[i].maxnum_allbuffs);
		printf("pool[%d]malloc_missing : %d\n ",i,pool[i].malloc_missing);
		if(pool[i].maxnum_allbuffs >= pool[i].total-2)
			printf("===========> pool[%d] buffers are almostover <===========\n",i);
	}
	printf("=====> end of mythyread3 function <=====\n");
	check_mem_leak();
	return 0;
}


int main()
{
	int i=0;
	printf("=====> in main function <=====\n");
	pthread_t tid;
	mem_init();
	while(i<3)
	{
	pthread_create(&tid,NULL,my_thread1,NULL);

	sleep(1);

	pthread_create(&tid,NULL,my_thread2,NULL);

	sleep(2);


	pthread_create(&tid,NULL,my_thread3,NULL);
	sleep(3);
	i++;
	}
	pthread_join(tid,NULL);
	printf("=====> end of main function <=====\n");
	return 0;
}



