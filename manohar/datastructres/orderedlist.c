#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t
{
	int pages;
	struct node_t *next;
}node;

node *head=NULL;

main()
{
	ordered_list(5);
	ordered_list(8);
	ordered_list(3);
	ordered_list(6);
	ordered_list(4);
	ordered_list(9);
	ordered_list(2);
	display();
}
int ordered_list(int val)
{
	node *temp=NULL,*old;
	node *new=malloc(sizeof(struct node_t));
	new->next=NULL;
	new->pages=val;
	if(head==NULL)
	{
		head=new;
		return;
	}
	if(head->pages > val)
	{
		new->next=head;
		head=new;
		return 0;
	}
	for(temp=head;temp!=NULL && temp->pages <= new->pages;temp=temp->next)
	{
		old=temp;
	}
	old->next=new;
	new->next=temp;
}
int display()
{
	node *temp=NULL;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%d\n",temp->pages);
	}
	return 0;
}



