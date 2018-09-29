#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void afree(void *w);

struct node
{
	char *addr;
	int flag;
	struct node *next;
}node[6];

static int buff[6][10];

static void init_structure()
{
	int i=0;
	for( ;i<sizeof(buff)/sizeof(buff[i]);i++)
	{
		node[i].addr=buff[i];
		node[i].flag=1;
	}
}

static void checking_thread_creation(char *n,int td)
{
	if(n == NULL)
	{
		printf("---->T%d amalloc is Failed\n",td);
		sleep(3);
	}
	else
	{
		sleep(4);
		printf("-->T%d. Thread %d, pid :%d\n",td,(int)pthread_self(), getpid());
		afree(n);
		sleep(3);
	}
}
static void status_of_nodes()
{
	int i=0,free=0,alloc=0;
	for(i=0;i<sizeof(buff)/sizeof(buff[i]);i++)
	{
		if(node[i].flag == 1)
		{
			free++;
		}
		else
		{
			alloc++;
			printf("---->Total Nodes %ld\t No.of Free Nodes %d \t,No.of	alloc Nodes%d\n",sizeof(buff)/sizeof(buff[0]),free, alloc);
		}
	}
}
char * amalloc(int n)
{
	int i;
	for(i = 0;i < sizeof(buff)/sizeof(buff[0]); i++)
	{
		if(node[i].flag == 1)
		{
			node[i].flag = 0;
			printf("---->Flag value %d ,Node %d allocated for %d\n",node[i].flag,i,n);
			return node[i].addr;
		}
	}
}


void afree(void *w)
{
	int i;
	for( i = 0; i < sizeof(buff)/sizeof(buff[0]); i++)
	{
		if(node[i].addr == w)
		{
			node[i].flag = 1;
			printf("---->Node %d Freeing\n",i);
		}
	}
	status_of_nodes();
}



static void* print_message_function()
{	
	char *p1;
	char *p2;
	char *p3;
	while(1)
	{	
		p1 = (void*)amalloc(10);
		checking_thread_creation(p1,1);
		p2 = (void*)amalloc(10);
		checking_thread_creation(p2,1);
		p3 = (void*)amalloc(10);
		checking_thread_creation(p3,1);
	}
	return NULL;
}

void* print_messagefunction()
{	
	char *q1;
	char *q2;
	char *q3;
	while(1)
	{
		printf("------>T2 asking for buffer\n");
		q1 = (void*)amalloc(20);
		checking_thread_creation(q1,1);
		q2 = (void*)amalloc(10);
		checking_thread_creation(q1,1);
		q3 = (void*)amalloc(30);
		checking_thread_creation(q1,1);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	int thread1_ret_val,thread2_ret_val;
	pthread_t thread1,thread2;
	init_structure();
	status_of_nodes();
	thread1_ret_val = pthread_create( &thread1,NULL,print_message_function,NULL);
	if(thread1_ret_val != 0)
	{
		printf("thread1 is not created\n");
		exit(0);
	}

	thread2_ret_val = pthread_create( &thread2, NULL,print_messagefunction,NULL);
	if(thread2_ret_val != 0)
	{
		printf("thread2 is not created\n");
		exit(0);
	}	

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}

