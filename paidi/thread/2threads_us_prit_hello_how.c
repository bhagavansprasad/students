#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
/* command gcc -lpthread filename.c */
volatile int a=0;
void * thread1()
{
	while(1)
	{
	    printf("a Hello!%d\n",a++);
		sleep(2);
	}
}

void * thread2()
{
	while(1)
	{
		printf("a How are you?%d\n",a++);
		sleep(2);
	}
}

int main()
{
	//int status;
	pthread_t tid1,tid2;

	pthread_create(&tid1,NULL,thread1,NULL);
	pthread_create(&tid2,NULL,thread2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
