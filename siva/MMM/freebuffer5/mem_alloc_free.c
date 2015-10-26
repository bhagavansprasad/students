#include "freebuffer5.h"
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
			return temp->fb;
		}

	}
	printf("Memory allocation failed\n");
	return NULL;
}

void afree(char *p)
{
	node *temp;
	int i;
	for(i=0;i<=4;i++)
	{
		for(temp=head[i];temp!=NULL;temp=temp->next)
		{
			if(temp->flag == 0 && temp->fb == p) 
			{
				temp->flag = 1;
			}
		}
	}
}

