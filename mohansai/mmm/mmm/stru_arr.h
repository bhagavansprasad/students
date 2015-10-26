#define thread_count 3
#define node_count 5
#define return_NULL NULL
#define ROW 2
#define COLUM 2


int semid;
//------------------------------------------------------------------

void acquire_semaphore(int semid);
void release_semaphore(int semid);

void * thread_function1(void *arg);	//thread function 1
void * thread_function2(void *arg);	//thread function 1
//void * thread_function3(void *arg);	//thread function 1
void * mmm_cli();

int  cal_buffer_size();

void print_status();
void arrstatus(int size);

//-------------------------------------

typedef struct bhead_t
{
	int size;
	int is_free;
	time_t time_stamp;
	int t_pid;
	void *buff;
}bhead;


typedef struct btail_t
{
	char overflow[4];
}btail;


typedef struct free_buffs_t
{
	bhead front;
	btail rear;
	struct free_buffs_t *next;
}free_buff_list;


typedef struct hash_list_t
{
	int size;
	int total;
	int tot_available;
	int tot_allocs;
	int tot_frees;
	int tot_misses;
	free_buff_list *h;
}hash_list;



