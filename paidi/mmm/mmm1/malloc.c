#include"mmm1.h"

mempool m[5]={0};

int mem_req[][2]={
	{2,  80 },
	{3,  150},
//	{2, 320},
//	{3,  400},
//	{10, 512},
//	{9,  104}
	};
char *str1 = "emmbeded c";
char *str2 = "aura network";
int avail_count()
{ 
    //printf("\n------------ tot_availabul --------------\n");
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
	//printf("\nThe ID of this thread is: %u\n\n", (unsigned int)pthread_self());
	printf("%5s %7s %7s %7s	%3s %7s\n","size","to_alcs","avaibl","tot_free","tot_miss","total");
	for(i = 0; i < sizeof(mem_req)/sizeof(mem_req[0]); i++)
	{
	   m[i].total = m[i].tot_miss +m[i].tot_free + m[i].tot_allocs + m[i].avail;
		printf("%4d %5d %6d %7d %11d %7d",mem_req[i][1],m[i].tot_allocs,m[i].avail,m[i].tot_free,m[i].tot_miss,m[i].total);
		for(temp = m[i].head;temp != NULL;temp = temp->next)
		{
			printf("%5c\t ",(temp->flag ? 'F' : 'A'));
	       //printf("time %2ld\t",temp->time);
			//	printf("Id %5u\t",temp->Id);
		}
		printf("\n");
		sleep(2);
	}
}
void memory_leak(void)
{
    printf("\n<--------- memory leak--------->\n");
	node *temp;
	long  t;
	int i,diff;
	      printf("%8s %8s %10s\n","time","size","thread Id");
    	for(i = 0; i < sizeof(mem_req)/sizeof(mem_req[0]); i++)
	{
		for(temp = m[i].head;temp != NULL;temp = temp->next)
		{
			if(temp->flag == 0)
			{   
			    time(&t);
	            printf("%6ld %8d %13u\n",time(&t)-(temp->time),*(int *)(temp->fb),temp->Id);
				if(diff > 10)
				{
					temp->flag=1;
				}
			}
			
		}
	}
}

int gen_hashkey(int size)
{
	int i;
	//printf("hk %d    ",size);
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
	//printf("\nsizeof(mem_req)/ sizeof(mem_req[0])= %ld\t",sizeof(mem_req)/sizeof(mem_req[0]));
	for(i=0;i<sizeof(mem_req)/sizeof(mem_req[0]);i++)
	{
		//printf("\n-->%4d.  %4d    %4d\n", i, mem_req[i][0], mem_req[i][1]);
		// printf("--init_free_pool---------------------->%d\n",mem_req[i][0]);
		total_mem += mem_req[i][0] * mem_req[i][1]+(sizeof(node)+sizeof(buff_head)+sizeof(buff_tail));
		tot_buff +=mem_req[i][0];
	}
	p=malloc(total_mem);
	for(i=0; i < sizeof(mem_req)/sizeof(mem_req[0]) ; i++)
	{
		m[i].total = mem_req[i][0];
		for(j = 0; j< mem_req[i][0]; j++)
		{
			add_to_free(p,mem_req[i][1] );
			p = p + (mem_req[i][1] +(sizeof(node))+ sizeof(buff_head) + sizeof(buff_tail));
		}
	}

}

int add_to_free(char *p,int size)
{
	node *new,*temp;
  // *(int *)(p+sizeof(node)) = size;
	//printf("%d\n",size);
	int hk;

    new = (node*)p;
	new->fb = p + sizeof(node);
	
	buff_head *buf = new->fb;
	strcpy(buf->hl,str1);
	buf->size = size;
    printf("string1-->  = %s size--> =%d\n",buf->hl,buf->size);
    
	buff_tail*tai = (buff_tail*)(p+ sizeof(node) + sizeof(buff_head) + size);
	strcpy(tai->name,str2);
	printf(" string2--> =%s\n",tai->name);

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
	if(m[0].head == 0)
	{
	 init_free_pool();
	}
	int i,hk;	
	hk=gen_hashkey(size);
	printf("\n-->amalloc: got request for %d buffer and returning :\n", size);
	for(i = hk; i < sizeof(mem_req)/ sizeof(mem_req[0]); i++)
	{
		for(temp = m[i].head ; temp != NULL ; temp = temp->next)
		{
			if(temp->flag == 1)
			{
				//printf("amalloc-->thread ID: %u\n", (unsigned int)pthread_self());
				temp->flag = 0;
				temp->time= time(&t1);
				temp->Id =(unsigned int) pthread_self();
				m[i].tot_allocs ++;
				if(i != hk)
					m[hk].tot_miss ++;
					buff_head *buf = (buff_head *)temp->fb;
					printf("size=%d\n",buf->size);
					//printf("return  %u %u\n",temp->fb,(char*)(temp->fb)+sizeof(buff_head));
				return (temp->fb)+sizeof(buff_head);
			}
		}
	}
	m[hk].tot_miss++;
	printf("All buffers are over, memory is not allocated  ");
	return NULL;
}


int afree(char *p)
{
	node *temp;
	int size,hk,i;
	if (p == NULL)
	{
		printf("HOW CAN WE FREE THE NULL BUFF ?\n");
		return 0;
	}
	buff_head *buf = (buff_head *)(p - sizeof(buff_head));
	size = buf->size;
	buff_tail *tai = (buff_tail *)(p+size);
	printf("afree-->size=%d\n",size);

	hk  = gen_hashkey(size);
	for(temp = m[hk].head ; temp!=NULL ; temp=temp->next )
	{
		if((temp->fb)+sizeof(buff_head) == p)
		{
			printf("%s %s \n",buf->hl,tai->name);
			if(strcmp(buf->hl,str1) == 0)
			{
				if(strcmp(tai->name,str2) == 0)
				{
					if(temp->flag == 0)
					{
						temp->flag=1;
						m[hk].tot_free ++;
					}  
				}
				printf("tail is over flow %s\n",tai->name);
				return 0;
			}  
			printf("head is over flow %s\n",buf->hl);
				return 0;
		}
		return 0;
	}
	return 0;
}
