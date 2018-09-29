#include <stdio.h>
#include <stdlib.h>
#include "mem_req.h"

int hash_list(int buff_size, void * x);
int hash_key(int size);
int display();

int buff_req=0;
int row;
int * size_header;

struct node
{
	int flag;
	void *val;
	struct node *N;
};
struct node *h[sizeof(mem_req)/sizeof(mem_req[0])]={NULL};

main()
{
	int i=0,j=0;
	int size = 0;
	int k = 0;
	char *p;

	row =sizeof(mem_req)/sizeof(mem_req[0]);
	printf("rows :%d\n",row);

	for(i=0;i<row;i++)
	{
		buff_req = buff_req+mem_req[i][1];
	}
	printf("buff_req--->%d\n",buff_req);
	
	for(i=0;i<buff_req;i++)
	{
		size = size+(mem_req[i][0]*mem_req[i][1])+sizeof(struct	node)+sizeof(size_header);
	}
	
	printf("the size of memory is %d\n",size);

	p = malloc(size);
	printf("the address of p is %u\n",p);

	for(i=0; i < row; i++)
	{
		for(j=0;j<mem_req[i][1];j++,k++)
		{
			hash_list(mem_req[i][0],p);
			p = p + mem_req[i][0]+sizeof(struct node)+sizeof(size_header);
			printf("\n");
		}
	}

	display();
}

int hash_list(int buff_size, void * mem_ptr)
{
	int l;
	struct node *new,*temp;

	l = hash_key(buff_size);
	printf("the l value is %d\n",l);	
	
	new = mem_ptr;
	printf("the value of new is %u\n",new);
	printf("the size of the struct is %d\n",sizeof(struct node));

	size_header = mem_ptr+sizeof(struct node);
	printf("the address of the size_header %u\n",size_header);

	*size_header = buff_size;
	printf("the valu in the size_header %d\n",*size_header);

	new->flag = 0;
	
	new->val = mem_ptr+sizeof(struct node)+sizeof(size_header);
	printf("the value in the struct is %d\n",new->val);
	
	new->N = NULL;
	
	if(h[l]==NULL)
	{
		h[l]=new;
		return 0;
	}

	for(temp=h[l];temp->N!=NULL;temp=temp->N);
	temp->N=new;
	return 0;
}

int hash_key(int size)
{
	int i;
	
	for(i=0;i<buff_req;i++)
	{
		if(size == mem_req[i][0])
			return i;
	}
}

int display()
{
	int i;
	struct node *t;

	for(i=0;i<row;i++)
	{
		for(t=h[i];t!=NULL;t=t->N)
		{
			printf("flag-->%d\n",t->flag);
			printf("%u\t",t->val);
			printf("%u\n",t->N);
		}
	}

	return 0;
}
