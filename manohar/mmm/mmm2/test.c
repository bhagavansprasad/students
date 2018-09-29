#include "mmm.h"
#include "stdio.h"
#include "unistd.h"
#include <pthread.h>

void free_func(char *ptr,int x, int size)
{

	printf("The %d resource  is allocated to thread %d\n",size,x);
	sleep(1);

	printf("The buffer %d is going to free..\n",size);
	sleep(2);
	afree((void *)ptr);
	sleep(2);
}
void  *print_message_function2()
{
	char *ptr,*ptr1;
	int size = 100;
	int size1 = 200;

	while(1)
	{
		printf("Thread 1 Going to allocate Memory of size  %d\n",size);

		ptr =(void *) amalloc(size);
		ptr1=(void *) amalloc(size1);
		if (ptr != NULL && ptr1 != NULL)
		{
			free_func(ptr,1,100);
			free_func(ptr1,1,200);
		}
		else
			printf("%d resource is not free\n",size);

		sleep(1);
	}


}

void *print_message_function()
{
	char *ptr;
	int size = 200;

	while(1)
	{
		printf("Thread 2 Going to allocate Memory of size  %d\n",size);
		ptr = (void *) amalloc(size);
		if (ptr != NULL)
			free_func(ptr+4,2,200);
		else
			printf("resource is not free\n");

		sleep(2);
	}

}



int main()
{
	pthread_t tid1,tid2;

	mmm_init();
	pthread_create(&tid1,NULL,(void *)print_message_function2,NULL);
	pthread_create(&tid2,NULL,(void *)print_message_function,NULL);

	sleep(30);
	return 0;

}
