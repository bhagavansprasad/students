#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

struct node *header;
main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	printf("stack list are :\n");
	display();
	pop();
	pop();
	printf("updating stack list are :\n");
	display();
}

int push(int n)
{
	struct node *new=NULL , *temp=NULL;
	new=(struct node*)malloc(sizeof(struct node));
	new ->data=n;
	new ->next=NULL;

	if(header==NULL)
	{
		header=new;
		return;
	}

	for(temp=header ; temp->next!=NULL ; temp=temp->next);

	temp->next=new;
}

int pop()
{
	struct node  *temp=NULL, *prev = NULL;
	for(temp=header ; temp!=NULL ; prev = temp ,temp=temp->next)
	{
		if( temp -> next == NULL)
		{
			prev-> next  = temp -> next ;
			return;
		}
	}
}

int display()
{
	struct node *temp=NULL;
	for(temp=header ; temp!=NULL ; temp=temp->next)
	{
		printf("%d\n",temp->data);
	}
}
