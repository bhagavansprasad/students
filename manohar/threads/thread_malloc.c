#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
char buff[100];
int flag=1;

void* amalloc(int n)
{
	if(flag==1)
	{
		flag=0;
		printf("memory is allocated \n");
		return buff;
	}
	else
	{
		printf("buffer is not there\n");
		return NULL;
	}
}

void* afree(void* w)
{
	flag = 1;
	if(flag==1)
	{
		printf("memory is freed\n");
	}
	else
	{
		printf("memory is allocated\n");
	}
	return 0;
}

void* print_message_function(void *thread1)
{	
	while(1)
	{	
		char *p;
		p = (void*)amalloc(100);
		if(p == NULL)
		{
			printf("memory is not allocated for thread1\n");
			sleep(3);
		}
		else
		{
			sleep(3);
			printf("thread1---->%s\n",(char*)thread1);
			printf("this is pid %d \n", getpid());
			printf("this is tid %p \n",(void*)pthread_self());
			afree(p);
			sleep(3);
		}
	}
	return 0;
}

void* print_messagefunction(void *thread2)
{	
	while(1)
	{
		char *q;
		q = (void*)amalloc(100);
		if(q == NULL)
		{
			printf("memory is not allocated for thread2\n");
			sleep(3);
		}
		else
		{
			sleep(3);
			printf("thread2----->%s\n",(char*)thread2);
			printf("this is pid %d \n", getpid());
			printf("this is tid %p \n",(void*)pthread_self());
			afree(q);
			sleep(3);
		}
	}
	return 0;
}

int main()
{
	int thread1_ret_val,thread2_ret_val;
	pthread_t thread1,thread2;

	thread1_ret_val = pthread_create( &thread1,NULL,print_message_function,NULL);
	if(thread1_ret_val != 0)
	{
		printf("thread1 is not created\n");
		exit(0);
	}

	thread2_ret_val = pthread_create( &thread2, NULL, print_messagefunction,NULL);
	if(thread2_ret_val != 0)
	{
		printf("thread2 is not created\n");
		exit(0);
	}	
	while(1)
	{
		sleep(3);
		printf("this is pid %d\n",getpid());

	}
	return 0;
}


