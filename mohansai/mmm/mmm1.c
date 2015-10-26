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
	char *buff;
	struct free_buffs_t *next;
}free_buff_list;

free_buff_list *list[4]={NULL,NULL,NULL,NULL,NULL};


void init_freelist()
{
	int i=0;
	for(i=0 ;i < MAX; i++)
		list[i].is_free=1;	
}

int get_hash_key(int size)
{
	if(size<=128)
	return 0;
	else if(size<=256)
	return 1;
	else if(size<=512)
	return 2;
	else if(size<=1024)
	return 3;
	else if(size<=2048)
	return 4;
}

void * amalloc(int size)

{
	int i,key = 0;
	free_buff_list *new,*temp;	
	free_buff_list *h=NULL;	
	
	sop.sem_num = 0;
	sop.sem_op  = -1;
	sop.sem_flg = 0 ;
	semop(semid, &sop, 1);
	
	key = get_hash_key(size);
	h =list[key];
	
	new = malloc(sizeof(free_buff_list));
	new->buff=malloc(size);
	
	if(h==NULL)
		h==new;
	else
	{
		for(temp=h; temp!=NULL;temp=temp->next)
		{	
			if(temp->is_free == 1)
			{
				temp->is_free = 0;
				printf("list[%d].is_free is: Allocating \n", i);
				semctl(semid, 0, SETVAL, 1);
				return temp->buff ;	
			}
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
