#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	void *bptr;
	int flag;
	struct node *next;
};

struct buff_header_t
{
	struct node *ptr;
	int buff_len;

}buff_header;


struct node *free_pool[3]={NULL};

int mem_req[][2] = {
	{100, 5},
	{200, 5},
	{500, 4},
	{0, 0}
};

int hash_key_gen(int size)
{
	if(size == 100 )
		return 0;
	else if(size == 200)
		return 1;
	else if (size == 500)
		return 2;
}

void dump_free_pool(void)
{
	struct node *t ;
	int i;

	for (i = 0; mem_req[i][0] != 0 ; i++)
	{
		t = free_pool[i];

		while(t != NULL)
		{
			printf("h[%d]:--->addr:%p flag :%d next :%p\n", i, t->bptr, t->flag,  t->next);
			t = t->next;
		}

		printf("\n");
	}	
}

int add_buff_to_free_pool(void *pb, int buff_size)
{    
	struct node *new, *t;
	int hkey = 0;

	hkey = hash_key_gen(buff_size);

	printf(" add_buff_to_free_pool pb:%p", pb);
	printf("key  :%d\n", hkey);

	new = malloc(sizeof(struct node));
	*(int *)pb = buff_size;
	new->bptr = (char *)pb + sizeof(buff_header);
	new->flag = 1;

	new->next = free_pool[hkey];
	free_pool[hkey] = new;

	return 0;
}

int get_cumulative_mem_requirements()
{
	int size = 0;
	int i = 0;

	for (i = 0; mem_req[i][0] != 0 ; i++)
	{
		size =  size + mem_req[i][0] * (mem_req[i][1] + sizeof(buff_header));
	}

	return size;
}

void * amalloc(int size)
{
    int hkey,i;
	struct node *new;

	hkey = hash_key_gen(size);
	new = free_pool[hkey];

	printf("key  :%d\n", hkey);
		
	for( new = free_pool[hkey]; new != NULL; new = new->next)
	{
		if(new->flag==1)
		{  
		    new->flag=0;
			return new->bptr;
		}
	}
	return NULL;
}     

void * afree(void *ptr)
{
    int size=0, hkey;
	struct node *new;
	size = *(int *)((char *)ptr - sizeof(buff_header));
	
	hkey = hash_key_gen(size);
	new = free_pool[hkey];
	
	for( new = free_pool[hkey]; new != NULL; new = new->next)
	{
		if(new->flag == 0)
		{
			new->flag = 1;
	        printf("new->flag %d \n",new->flag);
			return;
		}
	}

	return NULL;
}


main()
{
	int i, j;
	int len = 0;
	char *gptr = NULL;
	int index = 0;
	int size = 0;
	int *p1,*p2,*p3,*p4;

	size = get_cumulative_mem_requirements();

	gptr = (char *)malloc(size);

	printf("gptr :%p\n", gptr);

	for(i = 0; mem_req[i][0] != 0 ; i++)
	{
		for(j = 0; j < mem_req[i][1]; j++)
		{
			add_buff_to_free_pool(gptr + index, mem_req[i][0]);
			index = index + mem_req[i][0] + sizeof(buff_header);
		}	
	}
	dump_free_pool();
	
	p1=amalloc(100);
	printf("p1: %p\n",p1);
	
	p2=amalloc(100);
	printf("p2: %p\n",p2);

	afree(p1);
	afree(p2);
	
	p3=amalloc(100);
	printf("p3: %p\n",p3);
	
	p4=amalloc(100);
	printf("p4: %p\n",p4);
	
	p1=amalloc(100);
	printf("p1: %p\n",p1);
}
