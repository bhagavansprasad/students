#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
char message2[]="hi welcome to aura";
char message1[]="u r welcome";
int buff[500],flag=0;
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
		printf("memory is  free:\n");
	}
	else
	{
		printf("the memory not free");
	}
}
void * thread_function1(void *arg)
{ 
    for (;;)
    {
        m=amalloc(10);
		printf("thread1 memory allocated\n");
		sleep(2);
		afree(m);
        printf("thread thread1 is running ,arguments are %s \n",(char*)arg);
        sleep(5);
    }
    strcpy(message1,"paidi");
    pthread_exit("thank you for the cpu time");
}
void * thread_function2(void *arg)
{
    for (;;)
    {
        m= amalloc(10);
		printf("thread2 memory allocated\n");
		sleep(2);
        afree(m);
       printf("thread thread2 is running ,arguments are %s \n",(char*)arg);
        sleep(3);
    }
    strcpy(message1,"net works");
    pthread_exit("thank you for the cpu time");
}

int main()
{
//	printf(" main process ID %d\n",getpid());
	int res,f1=1,f2=1;
	pthread_t a_thread;
	pthread_t b_thread;
	void *thread_result;
	res=pthread_create(&a_thread,NULL,thread_function1,(void *)message1);
	res=pthread_create(&b_thread,NULL,thread_function2,(void *)message2);
	for(;;)
	{
		sleep(2);
	}
	res=pthread_join(a_thread,&thread_result);
	res=pthread_join(b_thread,&thread_result);
	printf("thread joined it returned %s\n",(char *)thread_result);
//	printf("message is now message%s\n",message1);
}
