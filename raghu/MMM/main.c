#include <stdio.h>
#include <stdlib.h>
#include "mem_req.h"
#include <time.h>

int hash_list(int buff_size, void * x);
int hash_key(int size);
void* amalloc(int mem_req);
void afree(int * ptr);
int display();
int get_pid();

int buff_req=0;
int row;
int * size_header;

struct node
{
	int flag;
	void *val;
	int pid;
	char * time;
	struct node *N;
};
struct node *h[sizeof(mem_req)/sizeof(mem_req[0])]={NULL};

main()
{
	int i=0,j=0;
	int size = 0;
	int k = 0;
	char *p;
	int *process[12];

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

	printf("the size of memory required is %d\n",size);

	p = malloc(size);
	printf("the address present in p is %p\n",p);
	printf("\n");

	for(i=0; i < row; i++)
	{
		for(j=0;j<mem_req[i][1];j++,k++)
		{
			hash_list(mem_req[i][0],p);
			p = p + mem_req[i][0]+sizeof(struct node)+sizeof(size_header);
		}
	}
	display();
	process[0] = amalloc(100);
	sleep(1);
	process[1] = amalloc(100);
	sleep(1);
	process[2] = amalloc(100);
	sleep(1);
	process[3] = amalloc(200);
	sleep(1);
	process[4] = amalloc(200);
	sleep(1);
	process[5] = amalloc(200);
	sleep(1);
	process[6] = amalloc(200);
	sleep(1);
	process[7] = amalloc(300);
	sleep(1);
	process[8] = amalloc(300);
	sleep(1);
	process[9] = amalloc(300);
	sleep(1);
	process[10] = amalloc(300);
	sleep(1);
	process[11] = amalloc(300);
	sleep(1);

	display();

	afree(process[1]);

	display();
	process[2] = amalloc(100);

	display();
}

int hash_list(int buff_size, void * mem_ptr)
{
	int l;
	time_t now;
	struct node *temp;
	struct node *new;

	l = hash_key(buff_size);

	new = mem_ptr;

	size_header = mem_ptr+sizeof(struct node);

	*size_header = buff_size;

	new->val = mem_ptr+sizeof(struct node)+sizeof(size_header);
	new->flag = 0;
	time(&now);
	new->time = ctime(&now);
	new->pid = 0;
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

int get_pid()
{
	return getpid();
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

void * amalloc(int mem_req)
{
	int l;
	struct node *t;
	time_t now;

	l = hash_key(mem_req);

	for(t=h[l];t != NULL;t=t->N)
	{
		if(t->flag == 0)
		{
			t->flag=1;
			t->pid = get_pid();

			time(&now);
			t->time = ctime(&now);

			return t->val;
		}
	}
	return NULL;
}

void afree(int * ptr)
{
	struct node *t;
	int size,l;
	int *ptr1;

	ptr1 = ptr-sizeof(size_header)/4;
	size = *ptr1;

	l = hash_key(size);
	for(t=h[l];t!=NULL;t=t->N)
	{
		if(t->val == ptr)
		{
			t->flag=0;
			t->pid = 0;
		}
	}
}

int display()
{
	int i;
	struct node *t;
	printf("flag	Address		Next address	Pid		Time\n");
	for(i=0;i<row;i++)
	{
		for(t=h[i];t!=NULL;t=t->N)
		{
			printf("%d\t",t->flag);
			printf("%p\t",t->val);
			printf("%p\t",t->N);
			if(t->N == NULL)
			printf("\t");
			printf("%d\t",t->pid);
			printf("%s\n",t->time);
		}
	}
	printf("\n");
	return 0;
}
