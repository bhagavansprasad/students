#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"

void *thread()
{
	sleep(1);
	printf("--> Aura Networks\n");
}

void *myThreadFun(void *vargp)
{
	pthread_t tid;
	sleep(1);
	printf("Printing Aura Networks from Thread \n");
	pthread_create(&tid, NULL, thread, NULL);
	pthread_join(tid, NULL);
	return NULL;
}


int main()
{
	pthread_t tid;
	printf("Before Thread\n");
	
	pthread_create(&tid, NULL, myThreadFun, NULL);
	pthread_join(tid, NULL);
	
	printf("After Thread\n");
	exit(0);
}
