#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

struct node *header;
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_node(60);
	add_node(70);
	add_node(80);
	add_node(90);
	add_node(100);
	printf("inserting nodes are :\n");
	display();
	revlist();
}
int add_node(int n)
{
	struct node *new = NULL,*temp = NULL;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;

	if(header==NULL)
	{
		header=new;
		return;
	}

	for(temp=header ; (temp->next)!=NULL ; temp=(temp->next));

	temp->next=new;
}

int display()
{
	struct node *temp = NULL;
	for(temp = header ; temp != NULL; temp = temp -> next)
	{
		printf("%d ", temp -> data);
	}
	printf("\n");
}

int revlist()
{
	struct node *temp = NULL, *ptr = NULL , *c = NULL;
	for(temp = header ; temp -> next != NULL; temp = temp -> next);
	ptr = temp;
	c= ptr;
	while( ptr != header)
	{
		for( temp = header; temp -> next != ptr; temp = temp -> next);
		ptr -> next = temp;
		ptr = ptr -> next;
	}
	ptr -> next = NULL;
	printf("rev list are : \n");
	for( temp = c; temp != NULL; temp = temp -> next)
	{
		printf("%d ", temp -> data);
	}
	printf("\n");
	return 0;
}

