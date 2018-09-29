#define thread_count 3
#define node_count 5
#define return_NULL NULL
#define ROW 4
#define COLUM 2


typedef struct bhead_t
{
	int size;
	int time_stamp;
	int t_pid;
}bhead;

typedef struct free_buffs_t
{
	int is_free;
	void *buff;
	struct free_buffs_t *next;
}free_buff_list;

typedef struct hash_list_t
{
	int size;
	int tot_available;
	int allocs;
	int frees;
	int misses;
	free_buff_list *h;
}hash_list;



