#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
char message2[]="hi welcome to aura";
char message1[]="aura welcome u";

void *thread_function1(void *arg)
{
	
	for(; ;)
	{
	    
	    printf("the thread1 ID :%u\n prcess ID :%d\n ",(unsigned int)pthread_self(),getpid());
		sleep(1);
	}
	strcpy(message1,"bye");
	pthread_exit("thank u for the cpu time");
}

void *thread_function2(void *arg)
{

	for(; ;)
	{
	    
	    printf("the thread2 ID :%u\n prcess ID :%d\n ",(unsigned int)pthread_self(),getpid());
		sleep(1);
	}
	strcpy(message1,"bye");
	pthread_exit("thank you for the cpu time");
}

int main()
{
	int res;
	int f1=1,f2=1;
	pthread_t a_thread;
	pthread_t b_thread;
	void *thread_result;
   	res=pthread_create(&a_thread,NULL,thread_function1,(void *)message1);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}

	res=pthread_create(&b_thread,NULL,thread_function2,(void *)message2);
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
	printf("thread joined it returned %s\n",(char *)thread_result);
	printf("message is now message%s\n",message1);
	 for( ; ; )
	{
	printf("main PID of thread is : %u\n",(unsigned int)pthread_self());
	printf("main ID of process is : %d\n",getpid());
	}

}
