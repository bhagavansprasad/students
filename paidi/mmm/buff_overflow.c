#include<stdio.h>
#include<stdlib.h>


int add_to_freebuff(char *,int );
void init_freepool();
void *thread_function4(void);
void *amalloc(int);
int afree(char *);


typedef struct node
{
	void *s;
	int flag;
	struct node*next;
}node;

node *hashhead[5]={NULL};

int mem_req[][2]={
	{10, 20},
	{ 5, 50},
	{10,120},
	{ 5,256},
	{10,512}
};

void init_freepool()
{
	int i,j,total_mem_req=0;
	char *p;

	for(i=0;i<sizeof(mem_req)/sizeof(mem_req[0]);i++)
		total_mem_req += mem_req[i][0] * (mem_req[i][1]);

	p=malloc(total_mem_req);

	for(i=0; i < sizeof(mem_req)/sizeof(mem_req[0]) ; i++)
	{
		for(j=0; j< mem_req[i][0]; j++)
		{
			add_to_freebuff(p,mem_req[i][1] );
			p = p + (mem_req[i][1] + 4);
		}
	}

}

int add_to_freebuff(char *p,int size)
{
	//printf("in add to free buff p is %u\n",p);
	*(int *)p=size;
	int hk;
	node *new,*temp;
	new=malloc(sizeof(node));

	new->s=malloc(sizeof(p));
	new->s=p;
	new->flag=1;
	new->next=NULL;

	hk=hashkeygen(size);

	//printf("in add to free buff hk is %d\n ",hk);
	if(hashhead[hk]==NULL)
	{
		hashhead[hk]=new;
		new->next=NULL;
		//printf("in add to free buff p is --> %u %d %u\n",new->s,new->flag,new->next);
		return 0;
	} 

	for(temp=hashhead[hk];temp->next!=NULL;temp=temp->next);
	temp->next=new;
	new->next=NULL;
	//printf(" p is -->%u %d %u\n",new->s,new->flag,new->next);
	return 0;
}

int hashkeygen(int size)
{
	int i;
	//printf("size %d ",size);
	for(i=0;i<sizeof(mem_req)/sizeof(mem_req[0]);i++)
	{
		if(size <= mem_req[i][1])
			return i;
	}
	return i+1;

}


void *amalloc(int size)
{
	int i;	
	int hk;
	node *temp;
	hk=hashkeygen(size);
	for(i=hk;i<5;i++)
	{
		for(temp = hashhead[i]; temp != NULL ; temp=temp->next)
		{
			if(temp->flag == 1)
			{
				temp->flag = 0;
				printf("buff %d is allocated for ",i+1);
				temp->flag = 0;
				return (temp->s)+4;
			}
		}
	}

	printf("All buffers are over, memory is not allocated for ");
	return NULL;
}


int afree(char *p)
{
	int i,hk;
	node *temp;
	int size;
	if(p)
	{
		size=(*((int *)p-1));
		hk=hashkeygen(size);
		for(temp = hashhead[hk]; temp!=NULL ; temp=temp->next )
		{
			if((temp->s)==(p-4))
			{
				if(temp->flag == 0)
				{
					printf("buff %d  is freed\n",hk+1);
					temp->flag=1;
					return 0;
				}
				printf("buff %d is already freed\n",hk+1);
				return 0;
			}
		}
	}
	printf("how can we free the null buff???\n");
	return 0;
}



void *thread_function1()
{ 
	char *p1,*p2,*p3,*p4;
	int i,j;
	//--------------what if all buffers are over---------
	for( i=0; i< sizeof(mem_req)/sizeof(mem_req[0]) ; i++)
	  {
	  for(j=0; j<mem_req[i][0]; j++)
	  {
	  p1 = amalloc(mem_req[i][1]);
	  printf("for thread 1\n");
	  }
	  }
	  p1=amalloc(20);
	  printf("for thread 1\n");
	 
}


main()
{	
	init_freepool();
	int res;
	pthread_t d_thread;
	void *thread_result;

	sleep(2);
	res=pthread_create(&d_thread,NULL,thread_function1,NULL);	
	res = pthread_join(d_thread,&thread_result);
}

