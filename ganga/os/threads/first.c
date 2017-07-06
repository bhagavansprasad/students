#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"

void *myThreadFun(void *vargp)
{
	sleep(1);
	printf("Printing GeeksQuiz from Thread \n");
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
