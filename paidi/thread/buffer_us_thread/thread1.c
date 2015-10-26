#include "stdio.h"
#include"pthread.h"
#include "stdlib.h"
#include "string.h"
char msg2[]="Hi welcome to aura";
char msg1[]="Aura welcomes you";
void *thread_function1(void *arg)
{
	for(;;)
	{
		//printf("thread 1 is running ,arguments was   %s \n",(char*)arg);
		int i=10,j=20;
		 printf("sum= %d\n",i+j);
		sleep(1);
	}
	strcpy(msg1,"bye");
	pthread_exit("thank you for cpu time" );
}
void *thread_function2(void *arg)
{
	for(;;)
	{
		printf("thread 2 is running ,argument was %s\n",(char*)arg);
		sleep(1);
	}
	strcpy(msg1,"bye");
	pthread_exit("thank you for cpu time ");
}
int main()
{
	int res,f1=1,f2=1;
	pthread_t a_thread;
	pthread_t b_thread;
	void *thread_result;
	res=pthread_create(&a_thread,NULL,thread_function1,(void*)msg1);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
	res=pthread_create(&b_thread,NULL,thread_function2,(void*)msg2);
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
	res=pthread_join(b_thread,&thread_result);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
	printf("thread joined it returned %s\n",(char*)thread_result);
	printf("message is now message %s\n",msg1);
}




