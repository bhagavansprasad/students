#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

struct node *header;
main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	printf("queue list are :\n");
	display();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	printf("updating queue list are :\n");
	display();
}

int enqueue(int n)
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

int dequeue()
{
	header=header->next;
}
int display()
{
	struct node *temp=NULL;
	for(temp=header ; temp!=NULL ; temp=temp->next)
	{
		printf("%d\n",temp->data);
	}
}





