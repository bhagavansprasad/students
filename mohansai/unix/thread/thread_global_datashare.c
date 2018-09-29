#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#include "string.h"
int i=10;

void * thread_function1(void *arg)
{
	for (;;)
	{
		//printf("thread thread1 is running ,arguments was %s \n",(char*)arg);
		i++;
		printf("thread1 %d\n",i);
	//	sleep(1);
	
	}
	//strcpy(message1,"bye");
	pthread_exit("thank you for the cpu time");
}

void * thread_function2(void *arg)
{
	for (;;)
	{
		//printf("thread thread2 is running ,arguments was %s \n",(char*)arg);
		i++;
		printf("thread2 %d\n",i);
	//	sleep(1);
	}
	//strcpy(message1,"bye");
	pthread_exit("thank you for the cpu time");
}



int main()
{
	int res;
	pthread_t a_thread;
	void*thread_result;
	int f1=1,f2=1;
	res = pthread_create(&a_thread, NULL, thread_function1, NULL);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}

	res = pthread_create(&a_thread, NULL, thread_function2,NULL );
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
	printf("waiting  for thread to finish \r\n");
	
	
	res=pthread_join(a_thread,&thread_result);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
//	printf("thread joined it returned %s\n",(char*)thread_result);
//	printf("message is now message %s \n",message1);
	sleep(1000);
}

