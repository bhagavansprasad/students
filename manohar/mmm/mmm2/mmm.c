#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errno.h"
#include "mem_req.h"
#include<time.h>
#include <pthread.h>
#include<signal.h>
#include <sys/time.h>
#include<unistd.h>

struct instrumentation
{
int tot_count;
int tot_allocs;
int tot_frees;
int tot_misses;
int tot_max_allocs;
int tot_leaks;
}instr;
typedef sturct 
{
str instr;
};
struct node
{
	int flag;
	void *ptr;
	struct node *next;
};
typedef struct header_t
{
	char size[4];
	char huni_head[4];
	time_t time_stamp;
	int tid;
}HEAD;
typedef struct tail_t
{
	char tuni_head[4];
}TAIL;

#define UNIQUE_HEAD "aBcD"
#define UNIQUE_TAIL "wXyZ"

static struct node *head[2];

int gethashkey(int size)
{
	if(size == 100)
		return 0;
	else if(size == 200)
		return 1;
	else
		return (-1);
}

void* add_to_pool(int size,char *buff1_st,char *buff1)
{
	struct node *q,*temp;
	int j=-1;
	j = gethashkey(size);
	temp = (void *)buff1_st;
	temp->flag = 1;
	temp->ptr=(buff1 + sizeof(HEAD));
	temp->next = NULL;
	*buff1 = size;

	strncpy(buff1 + sizeof(TAIL),UNIQUE_HEAD,4);
	strncpy((buff1 +sizeof(HEAD) + size),UNIQUE_TAIL,4);
	if (head[j]==NULL)
		head[j]=temp;
	else
	{
		q=head[j];
		while(q->next != NULL)
		{
			q=q->next;
		}
		q->next=temp;

	}

	return NULL;
}

void * mem_ret(struct node *head)
{	
	struct node *p;

	p = head;
	while(p->flag != 1 && p != NULL)
		p = p->next;
	if(p->flag == 1)
	{
		p->flag = 0;
		time(&((HEAD *)(p->ptr))->time_stamp);
		((HEAD *)(p->ptr))->tid = pthread_self();
		printf(" The Thread id is in MMM %u \n ",((HEAD *)(p->ptr))->tid);

		printf(" The time stamp %u \n ",(unsigned int)((HEAD *)(p->ptr))->time_stamp);
		return (p->ptr);
	}
	else 
		return NULL;

	return 0;
}
typedef void (t_callback) (union sigval si);

void* amalloc(int size)
{
	int hk = gethashkey(size);

	if(hk >= 0)
		return mem_ret(head[hk]);
	else
		return NULL;
}

int bufferoverflow(char *p)
{
	printf("bufferoverflow string %s\n",(p-sizeof(HEAD)+sizeof(int)));
	return(strncmp(p-sizeof(HEAD)+sizeof(int),UNIQUE_HEAD,4));
}

void afree(void *p)
{
	struct node *p1;
	int return_val,hk = -1;
	unsigned int size = *((int *)((char *)p -sizeof(HEAD)));

	printf("  buffer size is  %d ", size);

	hk = gethashkey(size);
	p1 = head[hk];
	return_val = bufferoverflow(p);
	if(return_val == 0)
		printf("  return_val = %d Buffer Is Not overflow\n",return_val);
	else
		printf("  buffer is not overflowed\n ");

	while(p1->ptr != (void *)p)
		p1 = p1->next;

	if(p1->ptr == (void *)p)
	{
		printf("buffer %d will successfully freed\n",size);
		p1->flag = 1;
	}
	return;
}

void is_mem_leak (union sigval si)
{
	struct node *k;
	time_t end,start;
	double elap;
	int i;

	for(i = 0; i < 2; i++)
	{
		k=head[i];

		while(k != NULL)
		{
			if(k->flag == 0)
			{
				start=((HEAD *)(k->ptr))->time_stamp;
				printf("in leak The start time is %u \n",(unsigned int )start);
				time(&end);     
				printf("in leak the end time is %u  \n",(unsigned int )end);       
				elap=difftime(end, start);
				printf(" time difference is %lf",elap);
				if(elap >= 15)
				{
					k=k->next;
					printf("\n Elapsed\n");
					k->flag=1;
					printf("The Buffer freed....\n");

					return;
				}
				else
				{
					k=k->next;
					printf("\n No elaps\n");
					return;
				}
				return ;
			}
		}
	}
}


int set_timer(float delay, float interval, t_callback func) 
{
	int status =0;
	struct itimerspec ts;
	struct sigevent se;
	timer_t tmid;

	delay = 3;

	se.sigev_notify = SIGEV_THREAD;
	se.sigev_value.sival_ptr = NULL;
	se.sigev_notify_function = is_mem_leak;
	se.sigev_notify_attributes = NULL;

	status = timer_create(CLOCK_REALTIME, &se, &tmid);
	if (status < 0)
	{
		perror("-->timer_create returned");
		printf("-->timer_create status :%d, errno :%d\n", status, errno);
	}

	printf("timer ID is 0x%lx\n", (long) tmid);

	ts.it_value.tv_sec = delay;
	ts.it_value.tv_nsec = 0;
	ts.it_interval.tv_sec =  ts.it_value.tv_sec;
	ts.it_interval.tv_nsec = ts.it_value.tv_nsec;

	status = timer_settime(tmid, 0, &ts, NULL);
	if (status < 0)
	{
		perror("-->timer_settime returned");
		printf("-->errno :%d\n", errno);
	}
	printf("-->timer_settime status :%d\n", status);

	return 0;
}
void display(void)
{
	struct node *q;
	int i;

	for(i=0; i < sizeof(buff)/sizeof(buff[0]); i++)
	{
		q=head[i];
		while(q != NULL)
		{
			printf("\n q.flag is \t %d  Buffer ptr is %p\n", q->flag, q->ptr);
			q=q->next;
		}
	}
	return;
}

static int free_pool_init(void)
{
	int i,j,total_mem_req;
	char *p;

	for(i = 0; i < sizeof(buff)/sizeof(buff[0]); i++)
		total_mem_req += (buff[i][0] * (buff[i][1] + sizeof(HEAD) + sizeof(TAIL))*buff[i][2]);

	printf("total mem req is  %d\n",total_mem_req);

	p = malloc(total_mem_req);

	for(i = 0; i < sizeof(buff)/sizeof(buff[0]); i++)
	{
		for(j = 0; j < buff[i][0]; j++)
		{
			add_to_pool(buff[i][1], p ,p + sizeof(struct node));
			p = p + (buff[i][1] +sizeof(struct node)+ sizeof(HEAD) + sizeof(TAIL));
		}
	}

	display();
	set_timer(1,1.0,is_mem_leak);

	return 0;
}
int mmm_init(void)
{
	free_pool_init();
	return 0;
}
















