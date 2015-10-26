#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "pthread.h"

char buf1[25][100];
char buf2[5][500];
char buf3[5][1000];

int add_to_free_pool(char *,int);

typedef struct _node
{
	char *fb;
	struct _node *next;
}node;

node *head[3]={NULL};

int init_free_pool()
{
	int i;
	for(i=0 ; i < 25; i++)
	{
		add_to_free_pool(buf1[i], 100);
	}

	for(i=0 ;i < 5; i++)
	{
		add_to_free_pool(buf2[i], 500);
	}

	for(i=0 ;i < 5; i++)
	{
		add_to_free_pool(buf3[i], 1000);
	}
}

int add_to_free_pool(char *b, int size)
{
	node *new, *temp;
	int hk;
	*(*int)b = size;
	new = malloc(sizeof(node));
	new->fb = b;
	new->next = NULL;

	hk = gen_hashkey(size);
	printf("-->hashkey ret val = %d\n",hk);
	if(head[hk] == NULL)
	{
		new->next = NULL;
		head[hk] = new;
		// printf("----------------hashkey\n");
		//printf("%u %d %u",new->fb,new->flag,new->next);
		return 0 ;
	}

	for(temp = head[hk]; temp->next != NULL; temp = temp->next);
	temp->next = new;
	new->next = NULL;
	//printf("%u %d %u",new->fb,new->flag,new->next);
	return 0;
}

int gen_hashkey(int size)
{
	if(size <= 100)
		return 0;
	else if(size > 100 && size <= 500)
		return 1;
	else if(size > 500 && size <= 1000)
		return 2;	
}

int main()
{
	int i;
	for(i=0;i<3;i++)
		init_free_pool();
}
