#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
char message2[]="hi welcome to aura";
char message1[]="u r welcome";
int buff[500];
int flag=0;
char *m;
void *amalloc(int);


void*amalloc(int n)
{
	if(flag==1)
	{
		printf("the memory is not allocated\n");
		sleep(3);
	}
	else
	{
		flag=1;
		printf("memory is allocated\n");
		return buff;
	}
}

void afree(char *m)
{
	flag=0;
	if(flag==0)
	{
		printf("memory is free :\n");
	}
	else
	{
		printf("the memory is not free \n");
	}

}

void * thread_function1(void *arg)
{ 
    for (;;)
    {
        m=malloc(10);
        printf("thread 1 ID IS = %u\n",(unsigned int)pthread_self());
		sleep(2);
		afree(m);
        printf("thread 1 Process id-->%d\n",getpid());
        sleep(2);
        printf("thread thread1 is running ,arguments was %s \n",(char*)arg);
        sleep(5);
    }
    strcpy(message1,"aura");
    pthread_exit("thank you for the cpu time");
}

void * thread_function2(void *arg)
{
    for (;;)
    {
        m= amalloc(10);
        printf("thread 2 ID IS = %u\n",(unsigned int)pthread_self());
        printf("thread 2 Process id-->%d\n",getpid());
        sleep(2);
		afree(m);
       printf("thread thread2 is running ,arguments was %s \n",(char*)arg);
        sleep(3);
    }
    strcpy(message1,"net works");
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

	for(;;)
	{
		sleep(2);
		printf("process ID%d\n",getpid());
		printf("main program \n");
	}
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

}
