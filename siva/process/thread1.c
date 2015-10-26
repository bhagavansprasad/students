#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#include "string.h"
void *amalloc(int);
char message2[] = "hi welcome to aura";
char message1[] = "aura welcomes u "; 
int buff[1000],flag=0;
char *m,*f;


void *amalloc(int n)
{

	if(flag==1)
	{
		printf("Memory is Not Allocated :\n");
		sleep(3);
	}
	else
	{   
	    flag = 1;
		printf("Memnory is allocated Successfully :\n");
		flag = 1;
		return buff;
	}
}

void afree(char *m)
{
	flag=0;
	if(flag == 0)
	{
		printf("SUCCESSFULLY DEALLOCATED :\n");
	}
	else
	{
		printf("NOT DEALLOCATED\n");
	}


}

void * thread_function1(void *arg)
{  
	m=(char *)amalloc(10);
	m=amalloc(40);
	//afree(m);

	for (;;)
	{
        m=malloc(40);
		printf("THREAD ID IS = %u\n",(unsigned int)pthread_self());
		printf("THREAD 1 Process id%d\n",getpid()); 
		sleep(2);
		printf("thread thread1 is running ,arguments was %s \n",(char*)arg);
		sleep(1);
	}
	strcpy(message1,"bye");
	pthread_exit("thank you for the cpu time");
}

void * thread_function2(void *arg)
{
	m= amalloc(10);
	free(m);
	m= amalloc(10);
	for (;;)
	{
	    m= amalloc(10);
		free(m);
		printf("THREAD ID IS = %u\n",(unsigned int)pthread_self());
		printf("THREAD 2 Process id%d\n",getpid()); 
		sleep(2);
		printf("thread thread2 is running ,arguments was %s \n",(char*)arg);
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


	res = pthread_create(&a_thread, NULL, thread_function1, (void*)message1);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}

	res = pthread_create(&b_thread, NULL, thread_function2, (void*)message2);
	if(res!=0)
	{
		perror("error in creating thread");
		exit(1);
	}

	printf("waiting  for thread to finish \r\n");

	for(;;)
	{
		sleep(2);
		printf("Process id%d\n",getpid()); 
		printf(" Main Programme \n");
	}


	res = pthread_join(a_thread, &thread_result);
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
	printf("message is now message %s \n",message1);
	//	sleep(1000);
}


