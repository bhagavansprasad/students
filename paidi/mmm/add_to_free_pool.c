#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* buff[6]={"paidi","ravi","tarun","prem","sudhir","siva"};

int add_to_free_pool(char *,int);
char *amalloc(int);

void *thread_function1(void *arg);
void *thread_function2(void *arg);
void *thread_function3(void *arg);
void *thread_function4(void *arg);
typedef struct _node
{
	void *fb;
	int flag;
	struct _node *next;

}node;
node *head=NULL;

int init_free_pool()
{
    int i;
	for(i=0;i<=5;i++)
	{
		add_to_free_pool(buff[i],100);
	}
}

int add_to_free_pool(char *b,int size)
{
	node *new, *temp;
	new=malloc(sizeof(node));
	new->fb=b;
	new->flag=1;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		return 0;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=new;
		return 0;
	}
}

char *amalloc(int size)
{
	node *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->flag==1)
		{
			temp->flag=0;
			return temp->fb;
		}
		else
		{
			return NULL;
		}

	}

}

void afree(char *p)
{
	node *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->fb == p)
		{
			temp->flag=1;
		}
	}

}
void *thread_function1(void *arg)
{
	for( ; ;)
	{
		char *p = amalloc(100);
		printf(" thread1 memory allocated\n");
		sleep(1);
		printf("------------------>:thread 1 is FREE\n");
		afree(p);
	}
}



void *thread_function2(void *arg)
{

	for( ; ;)
	{
		char *p = amalloc(100);
		printf(" thread2 memory allocated\n");
		sleep(1);
		printf("------------------>:thread 2 is FREE\n");
		afree(p);

       }

}

void *thread_function3(void *arg)
{

	for( ; ;)
	{
		char *p = amalloc(100);
		printf(" thread3 memory allocated\n");
		sleep(1);
		printf("------------------>:thread 3 is FREE\n");
		afree(p);

       }

}

void *thread_function4(void *arg)
{

	for( ; ;)
	{
		char *p = amalloc(100);
		printf(" thread4 memory allocated\n");
		sleep(1);
		printf("------------------>:thread 4 is FREE\n");
		afree(p);

       }

}

main()
{
       init_free_pool();
       pthread_t a_thread,b_thread,c_thread,d_thread;
       void *thread_result;
       int res;
       printf("main pid :%d\n", getpid());
       printf("waiting for thread to finsh \n");
         
	   res = pthread_create(&a_thread,NULL,thread_function1,(void*)NULL);
       res = pthread_create(&b_thread,NULL,thread_function2,(void*)NULL);      
       res = pthread_create(&b_thread,NULL,thread_function3,(void*)NULL);      
       res = pthread_create(&b_thread,NULL,thread_function4,(void*)NULL);      
       res = pthread_join(a_thread,&thread_result);
       res = pthread_join(b_thread,&thread_result);
       res = pthread_join(c_thread,&thread_result);
       res = pthread_join(d_thread,&thread_result);
       printf("thread joined it returned %s\n",(char*)thread_result);
}


