#include "stdio.h"
#include"pthread.h"
#include"stdlib.h"
#include "string.h"
int i=10;
void *thread_function1(void *arg)
{
	for(;;)
	{
		i++;
		printf("thread 1 %d\n",i);
		sleep(3);
	}
	//	strcpy(msg1,"bye");
	pthread_exit("thank you for cpu time" );
}
void *thread_function2(void *arg)
{
	for(;;)
	{
		i++;
		printf("thread 2 %d\n",i);
		sleep(3);
	}
	pthread_exit("thank you for cpu time" );
}
int main()
{
	int res,f1=1,f2=1;
	pthread_t a_thread;
	void *thread_result;
	res=pthread_create(&a_thread,NULL,thread_function1,NULL);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
	res=pthread_create(&a_thread,NULL,thread_function2,NULL);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
	printf("waiting for thread to finish\r\n");
	res=pthread_join(a_thread,&thread_result);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
	sleep(100);
}



