#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *myThreadFun(void *vargp)
{
    sleep(3);
    printf("Printing GeeksQuiz from Thread \n");
    printf("After Thread TID is : %u \n",pthread_self());
	printf("pid of the thread1 is : %d \n",getpid());
	printf("ppid of the thread1 is : %d \n",getppid());
    return NULL;
}
  
int main()
{
    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    //printf("After Thread TID is : %u \n",pthread_self());
	//printf("pid of the thread1 is : %d \n",getpid());
	//printf("ppid of the thread1 is : %d \n",getppid());
    exit(0);
}
