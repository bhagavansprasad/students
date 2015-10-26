#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "pthread.h"

char buf1[10][26];
char buf2[10][58];
char buf3[10][132];
char buf4[10][260];
char buf5[10][516];

int add_to_free_pool(char *,int);
char *amalloc(int);
void *thread_function1(void);
void *thread_function2(void);

typedef struct _node
{
	char *fb;
	int flag;
	struct _node *next;
}node;

node *head[5]={NULL};

int init_free_pool()
{
	int i;
	for(i=0 ; i < 10; i++)
	{
//		int *a = (int *)buf1[i];
//		 *a=26;
		add_to_free_pool(buf1[i], 26);
	}

	for(i=0 ;i<10; i++)
	{
//		int *b = (int *)buf2[i];
//		*b=58;
		add_to_free_pool(buf2[i], 58);
	}

	for(i=0 ;i<10; i++)
	{
//		int *c = (int *)buf3[i];
//		*c=132;
		add_to_free_pool(buf3[i], 132);
	}

	for(i=0 ;i<10; i++)
	{
//		int *d = (int *)buf4[i];
//		*d=260;
		add_to_free_pool(buf4[i], 260);
	}
	for(i=0 ;i<10; i++)
	{
//		int *e = (int *)buf5[i];
//		*e=516;
		add_to_free_pool(buf5[i], 516);
	}
}
  
int add_to_free_pool(char *b, int size)
{
	node *new, *temp;
	int hk;
	*(*int)b = size;
	new = malloc(sizeof(node));
	new->fb = b;
	new->flag = 1;
	new->next = NULL;

	hk = gen_hashkey(size);
		//printf("-->hashkey ret val = %d\n",hk);
	if(head[hk] == NULL)
	{
		new->next = NULL;
		head[hk] = new;
		// printf("----------------hashkey\n");
	//	printf("%u %d %u",new->fb,new->flag,new->next);
		return 0 ;
	}

	for(temp = head[hk]; temp->next != NULL; temp = temp->next);
	temp->next = new;
	new->next = NULL;
	//	printf("%u %d %u",new->fb,new->flag,new->next);
	return 0;
}

char *amalloc(int size)
{
	node *temp;
	int i, hk;
	printf("amalloc size---> %d\n",size);
	hk = gen_hashkey(size);

	for(temp = head[hk]; temp != NULL; temp = temp->next)
	{
		if(temp->flag == 1)
		{
			printf("------>buff %d is allocated	for ",hk+1);
			temp->flag = 0;
			return (temp->fb+4);
		}
	}
	return NULL;	
}

int afree(char *p)
{
	printf("in free addr is %u\n",p);
	node *temp;
	int size,hk;
	size=*((int *)p-1);
	printf("in free addr is %d\n",	p);
	hk=gen_hashkey(size);
	//printf("in free size is -->%d hk-->%d\n",size,hk);
	for(temp=head[hk];temp!=NULL;temp=temp->next)
	{
		if((temp->fb) == (p-4))
		{
			temp->flag=1;
			printf("----->buff %d  is free\n",hk+1);
			return 0;
		}
	}
}

void *thread_function3(void *arg)
{
  int i;
	node *temp;
	for( ; ; )
	{
		for(i=0;i<=5;i++)
		{
			printf("buff----->= %d\n",i);
			for(temp=head[i];temp!=NULL;temp=temp->next)
			{
			  printf(" %d",temp->flag);
			/*	printf ("buf1 IS %u FREE \n", (temp->flag == 1 ? " ": "NOT"));
				printf ("buf2 IS %u FREE \n", (temp->flag == 1 ? " ": "NOT"));
				printf ("buf3 IS %u FREE \n", (temp->flag == 1 ? " ": "NOT"));
				printf ("buf4 IS %u FREE \n", (temp->flag == 1 ? " ": "NOT"));
				printf ("buf5 IS %u FREE \n", (temp->flag == 1 ? " ": "NOT"));

				sleep(1);*/
			}
            printf("\n");
		}
	}
}


void *thread_function1()
{
	for( ; ;)
	{
		char *p1, *p2, *p3;
		p1 = amalloc(20);
		printf(" thread1 \n");
		sleep(2);
		afree(p1);

		p2 = amalloc(220);
		printf(" thread1 \n");
		sleep(3);
		afree(p2);

		p3 = amalloc(500);
		printf(" thread1 \n");
		sleep(2);
		afree(p3);

	}
}
void *thread_function2()
{
	for( ; ;)
	{
		char *p1, *p2, *p3;
		p1 = amalloc(10);
		printf(" thread2\n ");
		sleep(5);
		afree(p1);

		p2 = amalloc(100);
		printf(" thread2 \n");
		sleep(8);
		afree(p2);

		p3 = amalloc(300);
		printf(" thread2 \n");
		sleep(2);
		afree(p3);

	}
}

int gen_hashkey(int size)
{
	if(size <= 26)
		return 0;
	else if(size > 26 && size <= 58)
		return 1;
	else if(size > 58 && size <= 132)
		return 2;
	else if(size > 132 && size <= 260)
		return 3;
	else if(size > 260 && size <= 516)
		return 4;
	else
		return 5;
}

main()
{
	int res;
	pthread_t a_thread,b_thread,c_thread,d_thread;
	void *thread_result;

	init_free_pool();

	printf("waiting for thread to finsh \n");
	res = pthread_create(&a_thread,NULL,thread_function1,NULL);
	res = pthread_create(&b_thread,NULL,thread_function2,NULL);
	res = pthread_create(&c_thread,NULL,thread_function3,NULL);
	res = pthread_join(a_thread,&thread_result);
	res = pthread_join(b_thread,&thread_result);
	 res = pthread_join(c_thread,&thread_result);
	printf("thread joined it returned %s\n",(char*)thread_result);
}
