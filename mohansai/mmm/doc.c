#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "stdlib.h"
#include "time.h"
#include "pthread.h"
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/sem.h"
#include "stru_arr.h"

hash_list list[4];

int memory_requirements[ROW][COLUM]={{128, 5}, {256, 5}, {512, 10}, {1024,10}};

struct sembuf sop; //thread content
int semid;
//------------------------------------------------------------------

void acquire_semaphore(int semid);
void release_semaphore(int semid);
void * thread_function1(void *arg);	//thread function 1
void * thread_function2(void *arg);	//thread function 1
void * thread_function3(void *arg);	//thread function 1
void mmm_cli(void);

int  cal_buffer_size();

void allocation(void *ptr)
{
	int i,j;

	for(i=0; i < ROW; i++)
	{
		for(j=memory_requirements[i][1]; j>0 ; j--)
		{
			add_to_free_list(ptr,(memory_requirements[i][0]),(memory_requirements[i][1]) );
			ptr=(char*)ptr + memory_requirements[i][0]+sizeof(bhead);
		}
	}
}

void afree(void *ptr) // freeing the memory
{

	int i, key = 0;
	bhead *bh = NULL; // typcasting 
	hash_list *temp;	 
	hash_list *free_h;
	bh = (bhead *)(((char *)ptr)-4);

	//printf("------------->afree: thread :%d size :%d\n", (int)pthread_self(), bh->size);

	acquire_semaphore( semid);

	key = get_hash_key(bh->size);
	//printf("afree key--> %d\n", key);
	free_h = list[key];

	//printf("free in *p %d\n\r", bh->size);

	for(temp = free_h; temp!=NULL; temp=temp->h->next)
	{
		if(temp->h->is_free==0)
		{
			temp->h->is_free=1;
		}
	}
		 release_semaphore(semid);
}
//-----------------------------------------------------------
void * amalloc(int size)
{
	int i,key = 0;

	//printf("------->amalloc thread :%d size:%d\n", (int)pthread_self(), size);

	hash_list *temp;	
	hash_list *a_head;	

	acquire_semaphore( semid);

	key = get_hash_key(size);
	//	printf("amalloc key--> %d\n",key);
	a_head =list[key];

	for( temp = a_head ; temp!=NULL ; temp=temp->h->next )
	{	
		if(temp->h->is_free == 1)
		{	
			a_head->h->is_free = 0;
			//temp->t_pid=getpid();
//			h->time_stamp=time(0);
		 release_semaphore(semid);


			return (((char *)temp->h->buff)+sizeof(bhead));
		}
	}		
	//printf("*** malloc invalid memory to free ***\n");
	semctl(semid, 0, SETVAL, 1);
	return return_NULL;
}
//-------------------------------------------------------------------
int add_to_free_list(void *ptr, int size)
{
//	printf("ptr--> %d\n\r",ptr);
	hash_list  *hl;
	free_buff_list *new, *temp;
	bhead *bh = (bhead *)ptr;
	int key = 0;

	key = get_hash_key(size);
	hl = list[key];

	hl->size = size;
	hl->tot_available++;
	hl->allocs = 0;
	hl->frees = 0;
	hl->misses = 0;
	hl->h = NULL;

	bh->size = size;
	//printf("bh->size bh %p:%d\n", bh, bh->size);

	new = (free_buff_list *)malloc(sizeof(free_buff_list));
	new>is_free = 1;
	new>buff = ptr;
	new>next = NULL;

	if(hl->h == NULL)
		hl->h = new;
	else
	{
		for(temp = hl->h ; temp->next != NULL ; temp = temp->next );
		temp->next = new;
	}
	return 0;
}

int get_mem_chunk_size(void)
{
	int i, buffer_size=0;

	for( i=0 ; i < ROW ; i++ )
	{
		buffer_size +=(memory_requirements[i][0] + sizeof(bhead)) * memory_requirements[i][1];
	}		
	return buffer_size;
}


main()
{
	void *ptr;

	int buff_size,i = 0,res;

	pthread_t a_thread;
	pthread_t b_thread;
	pthread_t c_thread;
	pthread_t d_thread;

	semid = semget((key_t)0x25, 1, IPC_CREAT | 0666);
	semctl(semid, 0, SETVAL, 1);

	buff_size = get_mem_chunk_size();
	//printf("buffersize -->%d\n\r",buff_size);

	ptr=malloc(buff_size);

	//printf("ptr--> %d\n\r",ptr);

	allocation(ptr);
#if 0	
	display(128);
	display(256);
	display(512);
	display(1024);
#endif	
	res = pthread_create(&a_thread, NULL, thread_function1, NULL);
	res = pthread_create(&b_thread, NULL, thread_function2, NULL);
	res = pthread_create(&c_thread, NULL, thread_function3, NULL);
	res = pthread_create(&d_thread, NULL, mmm_cli, NULL);

	//printf("main waiting for thread to terminate...\n");
	pthread_join(a_thread,NULL);
	pthread_join(b_thread,NULL);
	pthread_join(c_thread,NULL);
	pthread_join(d_thread,NULL);


	display(128);
	display(256);
	display(512);
	display(1024);
	
	sleep(1000);
}
