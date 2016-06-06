

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

void *PrintHello(void *threadid)
{
	long tid;
	int pid;
	tid = (long)threadid;

	printf("Hello World! It's me, thread #%ld!\n", tid);
	printf("tid:%ld\n", tid);
	printf("pid: %d\n", getpid());
	sleep(200);
}
int a=10;
int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
    printf("before creating thread the value of a-->%d\n",a);
	for(t=0;t<NUM_THREADS;t++)
	{
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        printf("the value of a-->%d\n",a++);   
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

   
    printf("after  creating thread the value of a-->%d\n",a);
	sleep(200);
	/* Last thing that main() should do */
	pthread_exit(NULL);
}

