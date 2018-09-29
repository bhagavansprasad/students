#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>


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

//typedef struct hlist_h
//{
	
node *hlist[ROWS]={NULL};

void init_free_pool(char *p, int size, int bcount)
{
	int len = 0, i;

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
	node *t;
	int i;
	for(i=0;i<3;i++)
	{
		if(hlist[i]!=NULL)
		{
			t=hlist[i];
			for(t=hlist[i];t!=NULL;t=t->next)
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

int add_free_buffer(char *p, int size)
{
	int k = get_hash_key(size);
	node  *temp, *new;
	buffer_header *bh = NULL;
	buffer_tail *bt = NULL;
	new =(node *) p;

	printf("---->p is : %p\n", p);
	printf("---->size is : %d\n", size);

	bh =(buffer_header *)( p + sizeof(node)) ;
	bt = (buffer_tail *)(p + sizeof(node) + sizeof(buffer_header) + size);

	new->s =(p + sizeof(node)+sizeof(buffer_header));
	new->flag = 1; 
	new->next = NULL;

	bh->bp =(int *) p;
	bh->bsize = size;

	strcpy(bt->uniq_str, UNIQUE_STRING);

	printf("--------->tail1 : %s\n",(char *)bt);
	printf("--------->header : %p\n",bh);
	printf("--------->bh SIZE is : %d\n",	bh->bsize);
	printf("--------->BP is : %p\n",	bh->bp);
	printf("--------->p starting  address is : %p\n",p);

	printf("--------->actual buffer p->s is : %p\n",new->s);
	printf("--------->flag is : %d\n",new->flag);

	if(hlist[k] == NULL)
	{
		hlist[k] =(node *) p;
		return 0;
	}

	//TODO: NO need to insert at end, 
	//can be at beginning
	for(temp = hlist[k]; temp->next != NULL; temp = temp->next);

	temp->next =(node *) p;
	return 0;
}

int get_hash_key(int size)
{
	int i;
	for(i = 0; i < ROWS; i++)
	{
		if(size == MMM_Req[i][0])
		{
			printf("--------->hkey returning K: %d\n",i);
			return i;
		}
	}
}

void *amalloc(int size)
{
	node *temp;
	int hk;
	time_t t1;

	hk = get_hash_key(size);

	for(temp = hlist[hk]; temp != NULL; temp = temp->next)
	{
		if(temp->flag == 1)
		{
			temp->flag = 0;
			temp->tid =(unsigned int) pthread_self() ;

			temp->time = time(&t1); 
			printf("--------------->temp->time : %d \n",temp->time);
			printf("--------------->temp->tid :%u\n",temp->tid);
			printf("--------------->malloc returning: %p\n",((char
							*)temp+sizeof(buffer_header)+sizeof(node)));
			return ( ((char *)temp) + sizeof(buffer_header)+sizeof(node));
		}
	}

	return NULL;
}

void afree(void *p)
{
	node *temp;
	buffer_header *bh=NULL;
	buffer_tail *bt=NULL;
	int a;
	printf("---------------->size of buffer_header is : %d\n",sizeof(buffer_header));
	bh = (buffer_header *)((char *)p - sizeof(buffer_header));
	bt = (buffer_tail *) (char *)p + (bh->bsize);
	printf("---------------->buffer size is : %d\n",bh->bsize);
	printf("---------------->BP buffer is : %p\n",bh->bp);

	temp = (node *)(*((int*)p - 1));
	printf("---------------->value of P in afree:%p\n",p);

	printf("---------------->starting address value in afree: %p\n",temp);
	printf(" --------------->bt value tail address: %p\n",bt);

	a = memcmp(bt, UNIQUE_STRING,8);
	if (a != 0)
	{
		printf(".....>>>>>> over flow occured <<<<<<.....\n");
		printf(" -----> tid  : %u\n", temp->tid);
		printf(" -----> time : %u\n", temp->time);
	}
	printf("------>before free node->flag  : %d\n",temp->flag);

	temp->tid =  0;
	temp->time = 0;
	temp->flag = 1;
      
	printf("---->buffer size : %d is freeing now \n",bh->bsize);

	return;
}

void *my_thread1(void *vargp)
{
	char s[]="Networks";
	printf("size of string : %d\n",sizeof(s));
	int* tid = (int *)vargp;
	char *p;
	int i = 0;
	printf("-->T1 :%p\n", tid);

	p=amalloc(100);
	printf("Size is: %d\n", 100);
	printf("T1 :%p\n", p);

	while(p == NULL)
	{
		printf("-->T1 asking for bufffer for %d times\n", i++);
		sleep(1);
		p=amalloc(100);
		i++;
	}
	printf("-->T1 got for bufffer\n");
	printf("-->T1 using buffer\n");
	strcpy(p, s);
	printf("---------->UNIQUE_STRING :%s\n",UNIQUE_STRING );
	printf("-->T1 After using buffer\n");
	printf("-->T1 going for sleep for 3 sec\n");
	//sleep(2);
	printf("-->T1 going to free buffer adress is : %p\n",p);
	afree(p);
//	p=amalloc(500);
//	printf("Size is : %d\n", 500);
//	afree(p);
//	p=amalloc(1000);
//	printf("Size is: %d\n", 1000);
//	afree(p);

}

main()
{
	pthread_t tid;

	mem_init();
	pthread_create(&tid,NULL,my_thread1,NULL);
	pthread_join(tid,NULL);
}
