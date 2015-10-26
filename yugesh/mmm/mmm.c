#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>


#define ROWS 3

char buff1[100];
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

node *hlist[ROWS]={NULL};

void init_free_pool(char *p, int size, int bcount)
{
	int len = 0, i;

	for(i = 0; i < bcount; i++)
	{
		add_free_buffer(p + len, size);
		printf("P+LEN is : %d\n", p + len);
		len = len + (size + 8);
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
				printf("----->p : %d\n", t->s);
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
		size = size + ((MMM_Req[i][0]+8) * MMM_Req[i][1]);

	printf("size is : %d\n", size);

	p = malloc(size);

	for(i = 0; i < ROWS; i++)
	{
		init_free_pool(p + len, MMM_Req[i][0], MMM_Req[i][1]);
		len = len + (MMM_Req[i][0] * MMM_Req [i][1]);
	}

	display();
}

int add_free_buffer(char *p, int size)
{
	int k = get_hash_key(size);
	node *new, *temp;
	
	printf("---->p is : %d\n",p);
	printf("---->size is : %d\n",size);

	new = malloc(sizeof(node));
	*(int *)p      = size;
	*(int *)(p+4) = new;

	printf("*p SIZE is : %d\n",*(int *)p);
	printf("*(p+4) NEW is : %d\n",*(int *)(p+4));
	printf("----->new is : %d\n",new);

	//TODO: Not required here.  Move it to malloc. values are changed every time
	//the buffer is allocated

	//new->tid = pthread_self() ;
	//new->time = time ;
	new->s = p;
	new->flag = 1; 
	new->next = NULL;

	printf("new->s is : %d\n",new->s);
	printf("new->flag is : %d\n",new->flag);
	
	if(hlist[k] == NULL)
	{
		hlist[k] = new;
		return 0;
	}

	for(temp = hlist[k]; temp->next != NULL; temp = temp->next);

	temp->next = new;
	return 0;
}

int get_hash_key(int size)
{
	int i;
	for(i = 0; i < ROWS; i++)
	{
		if(size == MMM_Req[i][0])
		{
			printf("hkey returning K: %d\n",i);
			return i;
		}
	}
}

void *amalloc(int size)
{
	node *temp;
	int hk;

	hk = get_hash_key(size);

	for(temp = hlist[hk]; temp != NULL; temp = temp->next)
	{
		if(temp->flag == 1)
		{
			temp->flag = 0;
			return ( ((char *)temp->s) + 8);
		}
	}

	return NULL;
}

void afree(void *p)
{
	node *temp;

	printf("value of P in afree:%u\n",p);

	temp = *((int*)p-1);
	printf("temp value in afree: %u\n",temp);

	//if(temp->flag == 0)
	//{
	temp->flag=1;

	//TODO: set tid and time stamp to 0
	//new->tid = pthread_self() ;
	//new->time = time ;

	printf("Buffer's free now\n");
	//}
}
void *my_thread1(void *vargp)
{
	char s[15]="string";
	int tid = (int *)vargp;
	char *p;
	int i = 0;
	printf("-->T1 :%d\n", tid);

	p=amalloc(sizeof(buff1));
	printf("Size of Buff1: %d\n",sizeof(buff1));
	printf("T1 :%d\n", p);

	while(p == NULL)
	{
		printf("-->T1 asking for bufffer for %d times\n", i++);
		sleep(1);
		p=amalloc(sizeof(buff1));
		i++;
	}
	printf("-->T1 got for bufffer\n");
	printf("-->T1 using buffer\n");
	strcpy(p,s);
	printf("-->T1 After using buffer\n");
	printf("-->T1 going for sleep for 3 sec\n");
	sleep(2);
	printf("-->T1 going to free buffer\n");
	afree(p);
//	printf("-->T1 going for sleep for 5 sec\n");
//	sleep(5);
//	p=amalloc(sizeof(buff1));
//	printf("-->T1 got for bufffer\n");
//	printf("-->T1 using buffer\n");
}

main()
{
	pthread_t tid;
	
	mem_init();
    pthread_create(&tid,NULL,my_thread1,NULL);
	pthread_join(tid,NULL);
}
