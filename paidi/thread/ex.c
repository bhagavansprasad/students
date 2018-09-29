#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char message5[]="hai how ra u";
char message4[]="aura networks";
char message3[]="banglore";
char message2[]="where are you";
char message1[]="what are doing";
int buff3[1000];
int buff2[1000];
int buff1[1000];
int flag=0,i=0,j=0;
char *p;
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
		flag=1;
		return buff1;
	}

	if(i==1)
	{
		printf("the memory is not allocat\n");
		sleep(3);
	}
	else
	{
		i=1;
		printf("the memory is allocated\n");
		i=1;
		return buff2;
	}

	if(j==1)
	{
		printf("the memory is not allocated\n");
		sleep(3);
	}
	else
	{
		j=1;
		printf("the memory is allocated\n");
		j=1;
		return buff3;
	}
}

void afree(char *p)
{
	flag=0;
	if(flag==0)
	{
		printf("memory is allocated :\n");
	}
	else
	{
		printf("the memory is not allocated");
	}

    i=0;
	if(i==0)
	{
	 printf("memory is allocated :\n");
	}
	else
	{
	printf("memory is allocated :\n");
	}
    j=0;
	if(j==0)
	{
	printf("memory is not allocated :\n");
	}
	else
	{
	printf("memory is allocated :\n");
	}

}

void * thread_function1(void *arg)
{ 
	p=(char *)amalloc(10);
	p=amalloc(10);
	for (;;)
	{
		p=malloc(10);
		printf("thread ID IS = %u\n",(unsigned int)pthread_self());
		printf("thread 1 Process id-->%d\n",getpid());
		sleep(2);
	//	printf("thread thread1 is running ,arguments was %s \n",(char*)arg);
	//	sleep(1);
	}
	strcpy(message1,"aura");
	pthread_exit("thank you for the cpu time");
}

void * thread_function2(void *arg)
{

	p=(char *)amalloc(10);
	p=amalloc(10);
	for (;;)
	{
		p=malloc(10);
		printf("thread 2 ID IS = %u\n",(unsigned int)pthread_self());
		printf("thread 2 Process id-->%d\n",getpid());
		sleep(2);
	//	printf("thread thread 2 is running ,arguments was %s \n",(char*)arg);
	//	sleep(1);
	}
	strcpy(message1,"aura");
	pthread_exit("thank you for the cpu time");
}

void * thread_function3(void *arg)
{

	p=(char *)amalloc(10);
	p=amalloc(10);
	for (;;)
	{
		p=malloc(10);
		printf("thread 3 ID IS = %u\n",(unsigned int)pthread_self());
		printf("thread 3 Process id-->%d\n",getpid());
		sleep(2);
	//	printf("thread thread 3 is running ,arguments was %s \n",(char*)arg);
	//	sleep(1);
	}
	strcpy(message3,"aura");
	pthread_exit("thank you for the cpu time");
}

void * thread_function4(void *arg)
{

	p=(char *)amalloc(10);
	p=amalloc(10);
	for (;;)
	{
		p=malloc(10);
		printf("thread 4 ID IS = %u\n",(unsigned int)pthread_self());
		printf("thread 4 Process id-->%d\n",getpid());
		sleep(2);
	//	printf("thread thread 4 is running ,arguments was %s \n",(char*)arg);
	//	sleep(1);
	}
	strcpy(message4,"aura");
	pthread_exit("thank you for the cpu time");
}

void * thread_function5(void *arg)
{

	p=(char *)amalloc(10);
	p=amalloc(10);
	for (;;)
	{
		p=malloc(10);
		printf("thread 5 ID IS = %u\n",(unsigned int)pthread_self());
		printf("thread 5 Process id-->%d\n",getpid());
		sleep(2);
	//	printf("thread thread 5 is running ,arguments was %s \n",(char*)arg);
	//	sleep(1);
	}
	strcpy(message5,"aura");
	pthread_exit("thank you for the cpu time");
}




int main()
{
	int res;
	int f1=1,f2=1,f3=1,f4=1,f5=1;
	pthread_t a_thread;
	pthread_t b_thread;
	pthread_t c_thread;
	pthread_t d_thread;
	pthread_t e_thread;

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

	res=pthread_create(&c_thread,NULL,thread_function3,(void *)message3);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
	printf("waiting for thread to finish\r\n");

	res=pthread_create(&d_thread,NULL,thread_function4,(void *)message4);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}
	printf("waiting for thread to finish\r\n");

	res=pthread_create(&e_thread,NULL,thread_function5,(void *)message5);
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
