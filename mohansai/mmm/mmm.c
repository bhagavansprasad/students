#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#include "string.h"

#include "unistd.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/sem.h"

#define MAX 10

struct sembuf sop;
int semid;	

typedef struct free_buffs_t
{
	int is_free;
	char buff[100];
	struct free_buffs_t *next;
}free_buff_list;

free_buff_list list[MAX];



void init_freelist()
{
	int i=0;
	for(i=0 ;i < MAX; i++)
		list[i].is_free=1;	
}
void print()
{
	int i=0;
	for(i=0; i < MAX; i++)
	{
		printf("list[i].is_free=1--> %d\n",list[i].is_free);
		sleep(2);
	}
}

void * amalloc(int size)

{
	int i;

	sop.sem_num = 0;
	sop.sem_op  = -1;
	sop.sem_flg = 0 ;
	semop(semid, &sop, 1);

	for( i=0; i< MAX ; i++)
	{	
		if(list[i].is_free == 1)
		{
			list[i].is_free = 0;
			printf("list[%d].is_free is: Allocating \n", i);
			semctl(semid, 0, SETVAL, 1);
			return list[i].buff ;	
		}
	}		
	printf("*** No Free memory is available ***\n");
	semctl(semid, 0, SETVAL, 1);
	return NULL;
}

void afree(void *ptr)
{
	int i;
	sop.sem_num = 0;
	sop.sem_op  = -1;
	sop.sem_flg = 0 ;
	semop(semid, &sop, 1);
	for(i=0;i< MAX ; i++)
	{	
		if(ptr == list[i].buff )
		{
			list[i].is_free	=1;
			printf("list[%d].is_free: Releasing\n",i);
		}
	}
	semctl(semid, 0, SETVAL, 1);
	
}

void * thread_function1(void *arg)
{
	int i;
	char *ptr;

	for (i=0 ; i <100;  i++)
	{
		ptr = amalloc(100);

		sleep(2);

		afree(ptr);
	}
return NULL;
}

void * thread_function2(void *arg)
{
	int i;
	char *ptr;
	for (i=0 ; i <100;  i++)
	{
		ptr = amalloc(100);
		sleep(5);

		afree(ptr);
	}
return NULL;
}

void * thread_function3(void *arg)
{
	int i;
	char *ptr;
	for (i=0 ; i <100;  i++)
	{
		ptr = amalloc(200);
		sleep(3);

		afree(ptr);
	}
return NULL;
}

int main()
{
	int res;
	pthread_t a_thread;

	semid = semget((key_t)0x25, 1, IPC_CREAT | 0666);
	semctl(semid, 0, SETVAL, 1);

	init_freelist();

	res = pthread_create(&a_thread, NULL, thread_function1, NULL);
	res = pthread_create(&a_thread, NULL, thread_function2, NULL);
	res = pthread_create(&a_thread, NULL, thread_function3, NULL);

	sleep(1000);
return 0;
}
