#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "mmm.h"

int mem_req[][2]={
	{1,20},
	{2,50},
	{1,100},
	{2,70},
	{4,50}

};
node *hashhead[5]={NULL};

void *amalloc(int size)
{
	int i;	
	int hk;
	node *temp;
	hk = hashkeygen(size);
	for(i=hk;i<5;i++)
	{
		for(temp = hashhead[i].head; temp != NULL ; temp=temp->next)
		{
			if(temp->flag == 1)
			{
				temp->flag = 0;
				printf("buff %d is allocated for size %d\n",i+1,size);
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
	int hk;
	node *temp;
	int size;
	if(p != NULL)
	{
		size=(*((int*)p-1));
		hk = hashkeygen(size);
		for(temp = hashhead[hk];temp != NULL;temp = temp->next)
		{
			if(temp->s ==(p-4))
			{
				if(temp->flag == 0)
				{
					printf("buff %d is free\n",hk+1);
					temp->flag = 1;
					return 0;
				}
				printf("buff %d is already free\n",hk+1);
				return 0;
			}
		}
	}
	printf("how can we free the NULL buff?\n");
	return 0;
}


int add_to_freebuff(char *p,int size)
{
	printf("in add to free buff p is %p\n",p);
	*(int *)p=size;
	node *new,*temp;
	new=malloc(sizeof(node));

	new->s=malloc(sizeof(p));
	new->s=p;
	new->flag=1;
	new->next=NULL;

	int hk = hashkeygen(size);

	if(hashhead[hk].head==NULL)
	{
		hashhead[hk]=new;
		new->next=NULL;
		return 0;
	} 

	for(temp=hashhead[hk];temp->next!=NULL;temp=temp->next);
	temp->next=new;
	new->next=NULL;
	return 0;
}

int hashkeygen(int size)
{
	int i;
	printf(	" mem[0]  %d \n",sizeof(mem_req[1][1]));
	for(i=0;i<sizeof(mem_req)/sizeof(mem_req[0]);i++)
	{
		if(size <= mem_req[i][1])
			return i;
	}
	return i+1;

}


void init_freepool()
{
	int i,j,total_mem_req=0;
	char *p;
	printf("mem req is %d %d\n",sizeof(mem_req),sizeof(mem_req[0]));
	for(i=0;i<sizeof(mem_req)/sizeof(mem_req[0]);i++)
		total_mem_req += mem_req[i][0] * (mem_req[i][1]);

	printf("total mem req is  %d\n",total_mem_req);

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






















