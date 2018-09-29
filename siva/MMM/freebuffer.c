#include "struct.h"
char buff[10][100];

void *amalloc(int size)
{
	node *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->flag == 1)
		{
			temp->flag=0;
			return temp->fb;
		}
		else
		{
			return NULL;
		}
	}
}

void afree(char *p)
{
	node *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->flag == 0 && temp->fb == p) 
		{
			temp->flag = 1;
		}
	}
}

int add_to_free_pool(char *b,int size)
{
	node *temp,*new;
	new=malloc(sizeof(node));
	new->fb=b;
	new->flag=1;
	if(head==NULL)
	{
		new->next=NULL;
		head=new;
		return 0;
	}
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=new;
	new->next!=NULL;
	return 0;
}


void init_free_pool(void)
{
	int i;
	for(i=0;i<=9;i++)
	{
		add_to_free_pool(buff[i],100);
	}
}



main()
{
    char *am;
	init_free_pool();
	am=(char*)amalloc(50);
	if(am==NULL)
	{
	printf("No MEMORY IS ALLOCATED:\n");
	}
	afree(buff[0]);
}
