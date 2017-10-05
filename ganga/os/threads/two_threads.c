#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int c = 10;

void *thread1()
{
	while(1)
	{
		c = c + 2;
		printf("Hello!!\n");
		printf("the value of c in thread1: %d\n", c);
		sleep(2);
	}
}

void *thread2()
{
	while(1)
	{
		c++;
		printf("How are you?\n");
		printf("the value of c in thread2: %d\n", c);
		sleep(2);
	}
}

int main()
{
	int status;
	pthread_t tid1,tid2;

	pthread_create(&tid1,NULL,thread1,NULL);
	pthread_create(&tid2,NULL,thread2,NULL);
<<<<<<< HEAD
	printf("the value of c in proces : %d\n", c);
=======

>>>>>>> a6b6d6c95d169bceb183bb3e3d3291864e6206c8
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
