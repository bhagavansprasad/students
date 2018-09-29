#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	void *bptr;
	int flag;
	struct node *next;
};

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
			printf("h[%d]:--->addr:%u flag :%d next :%u\n", i, t->bptr, t->flag,  t->next);
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

//	printf(" add_buff_to_free_pool pb:%u", pb);
//	printf("key  :%d\n", hkey);

	new = malloc(sizeof(struct node));
	new->bptr = pb;
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
		size =  size + mem_req[i][0] * (mem_req[i][1]+4);
	}

	return size;
}

void *amalloc(int size)
{
	struct node *p;
	int key;

	key = hash_key_gen(size);

	p = free_pool[key];

	for(  ; p != NULL; p = p->next)
	{
		if(p->flag==1)
		{
			p->flag=0;
			return p->bptr;
		}	
	}

	return NULL;
}	

void afree(void *ptr)
{
	int i;
	struct node *p[3];

	for(i=0; i<3; i++)
	{
		if(ptr==NULL)
			break;

		p[i]=free_pool[i];

		for( ; p[i]!=NULL; p[i]=p[i]->next)
		{
			if(p[i]->bptr==ptr)
			{
				p[i]->flag=1;

				return;
			}
		}
	}
}	

void test_fun(void)
{
	char *p11,*p12,*p13,*p14,*p15,*p16,*p21,*p22,*p23,*p24,*p25,*p31,*p32,*p33,*p34;

	p11=amalloc(100);

	printf("p11:%u \n",p11);

	p12=amalloc(100);

	printf("p12:%u \n",p12);

	p13=amalloc(100);

	printf("p13:%u \n",p13);

	p14=amalloc(100);

	printf("p14:%u \n",p14);

	p15=amalloc(100);

	printf("p15:%u \n",p15);

	afree(p13);

	p16=amalloc(100);

	printf("p16:%u\n",p16);

	printf("p13:%u\n",p13);

}

void test_fun1(void)
{
	int *p1, *p2;

	p1 = (int *)amalloc(100);
}

main()
{
	int i, j;
	char *gptr = NULL;
	int index = 0;
	int size = 0;

	size = get_cumulative_mem_requirements();

	gptr = (char *)malloc(size);

	printf("gptr :%u\n", gptr);

	for(i = 0; mem_req[i][0] != 0 ; i++)
	{
		for(j = 0; j < mem_req[i][1]; j++)
		{
			add_buff_to_free_pool(gptr + index, mem_req[i][0]);
			index = index + mem_req[i][0];
		}	
	}

	dump_free_pool();

	test_fun();
}

