#include"mmm1.h"
mempool m[6]={0};
time_t time_stamp;

int mem_req[][2]={
	{2,  80 },
	{3,  150},
	{2, 320}
	//{3,  400},
	//{10, 512},
	//9,  104}
	};
int avail_count()
{ 
  printf("\n-----------> tot_availabul <-----------\n");
	int i;
	node *temp;
	for(i = 0; i < sizeof(mem_req)/sizeof(mem_req[0]); i++)
	{
	     m[i].avail =0;
		for(temp = m[i].head;temp != NULL;temp = temp->next)
		{
			if(temp->flag == 1)
			{
				m[i].avail++;
			}
		}
	}
}

void display_stats()
{
	int i;
	node *temp;
	avail_count();
//	printf("\nThe ID of this thread is: %u\n\n", (unsigned int)pthread_self());
	printf("%5s %7s %7s %7s	%3s %9s	\n","size","to_alcs","avaibl","tot_free","tot_miss","status");
	for(i = 0; i < sizeof(mem_req)/sizeof(mem_req[0]); i++)
	{
		printf("%4d %5d %6d %7d %11d ",mem_req[i][1],m[i].tot_allocs,m[i].avail,m[i].tot_free,m[i].tot_miss);
		for(temp = m[i].head;temp != NULL;temp = temp->next)
		{
			printf("%9c \t",(temp->flag ? 'F' : 'A'));
			//printf("time %2ld\t",temp->time);
			//	printf("Id %5u\t",temp->Id);
		}
		printf("\n");
		sleep(2);
	}
}
void test1(void)
{
	void *p1, *p2, *p3,*p4;
	printf("\n:_____test1_________\n");

	p1 = amalloc(330);
	sleep(1);
//	display_stats();

	p2 = amalloc(140);
	sleep(1);
//	display_stats();

	p3 = amalloc(20);
	sleep(1);
//	display_stats();
    p4 = amalloc(100);
	sleep(1);
	printf("\n: _________Freeing p2_________\n ");
//	display_stats();

//	afree(p1);
//	display_stats();
//	afree(p2);
//	display_stats();
	//afree(p3);
	display_stats();
}

void test2(void)
{
	void *p1, *p2, *p3, *p4;
	//	printf(": ______test2_______\n");
	p1 = amalloc(30);
	p2 = amalloc(15);
	p3 = amalloc(20);
	p4 = amalloc(20);
//	display_stats();
//	afree(p1);
//	afree(p2);
//	afree(p3);
//	afree(p4);
	display_stats();

}

void test3(void)
{
	void *p1, *p2, *p3, *p4;

	printf(": ________test3________\n");
	p1 = amalloc(30);
	p2 = amalloc(15);
	p3 = amalloc(20);
	p4 = amalloc(20);
	display_stats();
	afree(p1);
	afree(p2);
	afree(p3);
	afree(p4);
	display_stats();
}

void test4(void)
{
	void *p1, *p2, *p3, *p4;
	int i;
	printf(": _______test 4_______\n");
	for (i = 1; i <=15; i++)
	{
		display_stats();
		p1 = amalloc(20);
	}
	display_stats();
}
void *thread_function1(void*arg)
{ 
    	test1();
		test2();
	//	test3();
	//	test4();
	return 0;
}
void *thread_function2(void*arg)
{
    printf("\n<--------- memory leak--------->\n");
	node *temp;
	long  t;
	int i,diff;

	for(i = 0; i < sizeof(mem_req)/sizeof(mem_req[0]); i++)
	{
		for(temp = m[i].head;temp != NULL;temp = temp->next)
		{
			if(temp->flag == 0)
			{
			    
				diff = time(&t)-temp->time;
				printf(" diff----------->=%ld",diff);
				if(diff > 10)
				{
				    printf("time%d\n",temp->time);
				   // printf("\n Id%d\n",temp->Id);
				    printf(" size%d\n",mem_req[i][1]);
				//	printf("%8s %10s %14s\n","thread Id","time","size");
				//	printf("%20d %30d %30d",temp->Id,temp->time,mem_req[i][1]);
					temp->flag=1;
				}
			}
			
		}
	}
}

int gen_hashkey(int size)
{
	int i;
	printf("%d ",size);
	for(i = 0; i<sizeof(mem_req)/sizeof(mem_req[0]); i++)
	{
		if(size <= mem_req[i][1])
			return i;
	}
	return i+1;
}

void init_free_pool(void)
{
	int i,j,total_mem=0;
	char *p;
	int tot_buff = 0;
	printf("sizeof(mem_req)/ sizeof(mem_req[0])= %d\n",sizeof(mem_req)/sizeof(mem_req[0]));
	for(i=0;i<sizeof(mem_req)/sizeof(mem_req[0]);i++)
	{
		printf("-->%4d.  %4d    %4d\n", i, mem_req[i][0], mem_req[i][1]);
		// printf("--init_free_pool---------------------->%d\n",mem_req[i][0]);
		total_mem += mem_req[i][0] * (mem_req[i][0] + sizeof(node) + 4);
		tot_buff +=mem_req[i][0];
	}
	p=malloc(total_mem);
	for(i=0; i < sizeof(mem_req)/sizeof(mem_req[0]) ; i++)
	{
		m[i].total = mem_req[i][0];
		for(j = 0; j< mem_req[i][0]; j++)
		{
			add_to_free(p,mem_req[i][1] );
			p = p + (mem_req[i][1] +(sizeof(node))+ 4);
		}
	}

}

int add_to_free(char *p,int size)
{
	node *new,*temp;
	*(int *) (p + sizeof(node)) = size;
	int hk;
    new = p;
	new->fb   = p + sizeof(node) + 4;
	new->flag = 1;
	new->next = NULL;
	hk = gen_hashkey(size);
	if(m[hk].head== NULL)
	{
		m[hk].head = new;
		new->next   = NULL;
		return 0;
	}
	else
	for(temp = m[hk].head; temp->next != NULL;temp = temp->next);
	temp->next = new;
	new-> next =NULL;
	return 0;
}
void* amalloc(int size)
{
	node *temp;
	time_t t1;
	int i,hk;	
	hk=gen_hashkey(size);

	for(i = hk; i < sizeof(mem_req)/ sizeof(mem_req[0]); i++)
	{
		for(temp = m[i].head ; temp != NULL ; temp = temp->next)
		{
			if(temp->flag == 1)
			{
				temp->flag = 0;
				temp->time= time(&t1);
				temp->Id =(unsigned int) pthread_self();
				m[i].tot_allocs ++;
				if(i != hk)
				m[hk].tot_miss ++;
				return (temp->fb)+4;
			}
		}
	}
	m[hk].tot_miss++;
	//printf("All buffers are over, memory is not allocated  ");
	return NULL;
}


int afree(char *p)
{
	node *temp;
	int size,hk;
	if (p == NULL)
	{
		printf("HOW CAN WE FREE THE NULL BUFF ?\n");
		return 0;
	}
	size = ( *((int *)p - 1) );
	hk  = gen_hashkey(size);
	for(temp = m[hk].head ; temp!=NULL ; temp=temp->next )
	{
		if((temp->fb) == (p-4))
		{
			if(temp->flag == 0)
			{
				temp->flag=1;
				m[hk].tot_free ++;
			}      
		}
	}
	return 0;
}
int main()
{	
	init_free_pool();

	int res;
	pthread_t a_thread;
	pthread_t b_thread;
	pthread_t c_thread;
	pthread_t d_thread;
	void *thread_result;

	res=pthread_create(&a_thread,NULL,thread_function1,NULL);
	sleep(10);
	printf("=======================\n\n");
	display_stats();
	res=pthread_create(&b_thread,NULL,thread_function2,NULL);	
//	display_stats();
	//	res=pthread_create(&c_thread,NULL,thread_function3,NULL);	
	res = pthread_join(a_thread,&thread_result);
	res = pthread_join(b_thread,&thread_result);
	display_stats();
	//res = pthread_join(c_thread,&thread_result);

}
