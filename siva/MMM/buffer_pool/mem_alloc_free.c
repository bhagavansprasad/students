#include "freebuffer5.h"

extern node  *head[5];


void *amalloc(int size)
{
	node *temp;
	int i;
	char m;
	m=gen_hashkey(size);

	for(temp=head[m];temp!=NULL;temp=temp->next)
	{
		if(temp->flag == 1)
		{
			temp->flag=0;
			return temp->fb+4;
		}

	}
	printf("Memory allocation failed\n");
	return NULL;
}

void afree(char *p)
{
	node *temp;
	int  i;
	i=*((int *)p-1);
	int hashkey=gen_hashkey(i);
		for(temp=head[hashkey];temp!=NULL;temp=temp->next)
		{
			if(temp->flag == 0 && temp->fb == p+4) 
			{
				temp->flag = 1;
			}
		}
}


