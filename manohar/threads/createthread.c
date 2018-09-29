#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void* print_message_function( void* );

int main()
{
	pthread_t thread1;
	int i;
	for(i=0;i<=1;i++)
	{
	pthread_create( &thread1,NULL,print_message_function,NULL);
	}
	//pthread_create( &thread2, NULL, print_message_function,NULL);
	pthread_join( thread1, NULL);
	return 0;
}

void* print_message_function(void* thread1)
{	
	while(1)
	{
		printf("this is pid %d \n", getpid());
		printf("this is tid %p \n",(void*)pthread_self());
		sleep(1);
	}

	return 0;
}
