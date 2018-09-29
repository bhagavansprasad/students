#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
typedef struct _node
{
	void *fb;
	int flag;
	int time;
	int Id;
	struct _node *next;
}node;

typedef struct mempool
{
	int total;
	int avail;
	int tot_allocs;
	int tot_free;
	int tot_miss;
	node *head;
}mempool;

int add_to_free_pool(char *,int);
void *amalloc(int);
void *thread_function1(void *arg);
void *thread_function2(void *arg);
void *thread_function3(void *arg);
//void *thread_function4(void *arg);


