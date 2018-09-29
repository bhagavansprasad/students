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

memory_requirements[ROW][COLUM] = 
{
	{100, 2}, 
	{200, 3} 
};
//=============================================================
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
	else
		return 5;
}
//==========================================================

void acquire_semaphore(int semid)
{ 
	struct sembuf sop;

	sop.sem_num = 0;
	sop.sem_op  = -1;
	sop.sem_flg = 0 ;
	semop(semid, &sop, 1);
}


void release_semaphore(int semid)
{
	semctl(semid, 0, SETVAL, 1);
}

//==============================================================
void arr_status(int size)
{
	hash_list  *hl;

	hl = &list[get_hash_key(size)];
	
	printf("%-10d", size);
	printf("%-10d", hl->total);
	printf("%-18d", hl->tot_available);
	printf("%-12d", hl->tot_allocs);
	printf("%-14d", hl->tot_frees);
	printf("%-16d\n", hl->tot_misses);
}

void print_stats(void)
{
	int i,j;
	printf("hqueue | total | tot_available | tot_allocs | tot_frees | tot_misses\n");
	printf("====================================================================\n");
	for(i=0; i < ROW ; i++)
	{
			arr_status(memory_requirements[i][0]);
	}
	printf("\n\n");
}
//===============================================================
void allocation(void *ptr)
{
	int i,j;

	for(i=0; i < ROW; i++)
	{
		for(j=memory_requirements[i][1]; j>0 ; j--)
		{
			add_to_free_list(ptr, (memory_requirements[i][0]));
			ptr = (char*)ptr + (memory_requirements[i][0] + sizeof(free_buff_list));
		}
	}
}
//===================================================================
void afree(void *ptr) // freeing the memory
{
//	int key = 0;
	hash_list  *hl;
	free_buff_list *temp;

	printf("-->afree ptr   :%p\n\r",ptr );

	temp = (bhead *)(((char *)ptr) - sizeof(bhead));


//	key = get_hash_key(temp->front.size);
	//	printf("afree key--> %d\n", key);

	hl = &list[get_hash_key(temp->front.size)];
	
	acquire_semaphore( semid);
	//hl = &list[key];

	hl->tot_available++;
	hl->tot_frees++;

	temp->front.is_free = 1;
	temp->front.time_stamp = 0;
	temp->front.t_pid = 0;

	release_semaphore(semid);
}


void * amalloc(int size)
{
	//int i,key = 0;

	printf("-->amalloc thread :%u size:%d\n", (int)pthread_self(), size);

	hash_list  *hl;
	free_buff_list *temp;

//	key = get_hash_key(size);

	//	printf("key amalloc %d\n\r",key);

	acquire_semaphore(semid);

	hl = &list[get_hash_key(size)];

	//hl =&list[key];


	if(hl->tot_available!=0)
	{
		hl->tot_available--;
		hl->tot_allocs++ ;

		for (temp = hl->h; temp != NULL; temp = temp->next)
		{	
			if(temp->front.is_free == 1)
			{	
				//	printf("-->size     :%u :%d \n\r", &temp->front.size, temp->front.size);
				temp->front.is_free = 0;
				temp->front.time_stamp = time(0);
				temp->front.t_pid = getpid();
				release_semaphore(semid);
				//printf("--->buff    :%u \n\r", &temp->front.buff);
				return (temp->front.buff);
			}
		}
	}

	else 
	{
		hl->tot_misses++; 
		release_semaphore(semid);
		return NULL;
	}
}
//================================================================================
int add_to_free_list(void *ptr, int size)
{
	hash_list  *hl;
	free_buff_list *node, *temp;
	//int key = 0,count=0;

//	key = get_hash_key(size);

//	printf("-->key :%d\n", key);

	//hl = &list[key];
	
	hl = &list[get_hash_key(size)];
	
	hl->total++;
	hl->tot_available++;
	hl->size = size;
	hl->tot_allocs = 0;
	hl->tot_frees = 0;
	hl->tot_misses = 0;
#if 0	
	printf("-->total          %u :%d\n\r", &hl->total, hl->total);
	printf("-->tot_available  %u :%d\n\r", &hl->tot_available, hl->tot_available);
	printf("-->size           %u :%d\n\r", &hl->size, hl->size );
	printf("-->tot_allocs     %u :%d\n\r", &hl->tot_allocs, hl->tot_allocs);
	printf("-->tot_frees      %u :%d\n\r", &hl->tot_frees, hl->tot_frees);
	printf("-->tot_misses     %u :%d\n\r", &hl->tot_misses, hl->tot_misses);
#endif	 
	node = ptr;
	node->front.is_free = 1;
	node->front.size = size;
	node->front.time_stamp = 0;
	node->front.t_pid = 0;
	node->front.buff = ((char *)ptr) + sizeof(bhead);

#if 0	
	printf("-->is_free       :%u :%d \n\r", &node->front.is_free, node->front.is_free);
	printf("-->size         :%u :%d \n\r", &node->front.size, node->front.size);
	printf("-->time_stamp    :%u :%d \n\r", &node->front.time_stamp, node->front.time_stamp);
	printf("-->pid           :%u :%d \n\r", &node->front.t_pid, node->front.t_pid);
	printf("--->buff           :%u \n\r", &node->front.buff);
#endif	 

	node->next = NULL;

	if(hl->h == NULL)
		hl->h = node;
	else
	{
		for(temp = hl->h ; temp->next != NULL ; temp = temp->next );
		temp->next = node;
	}
	return 0;
}
//=============================================================================
int get_mem_chunk_size(void)
{
	int i, buffer_size=0;

	for( i=0 ; i < ROW ; i++ )
	{
		buffer_size +=(memory_requirements[i][0] + sizeof(free_buff_list)) * memory_requirements[i][1];
	}		
	return buffer_size;
}


main()
{
	void *ptr;
	char *p1;
	int buff_size,i = 0,res;

	pthread_t a_thread;
	pthread_t b_thread;
	//		pthread_t c_thread;
	pthread_t d_thread;

	semid = semget((key_t)0x25, 1, IPC_CREAT | 0666);
	semctl(semid, 0, SETVAL, 1);

	buff_size = get_mem_chunk_size();
	//printf("buffersize -->%d\n\r",buff_size);

	ptr=malloc(buff_size);

	//printf("ptr--> %d\n\r",ptr);

	allocation(ptr);

	print_stats();

	res = pthread_create(&a_thread, NULL, thread_function1, NULL);
	res = pthread_create(&b_thread, NULL, thread_function2, NULL);
	//		res = pthread_create(&c_thread, NULL, thread_function3, NULL);
	//res = pthread_create(&d_thread, NULL, mmm_cli, NULL);

	sleep(10);

	print_stats();

	printf("main waiting for thread to terminate...\n");
	pthread_join(a_thread,NULL);
	pthread_join(b_thread,NULL);
	//		pthread_join(c_thread,NULL);
	pthread_join(d_thread,NULL);
	sleep(1000);
}

