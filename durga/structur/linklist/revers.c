#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int n;
	struct node *link;	
};
struct node *new;
struct node *start = NULL;


int add( int num)
{
	struct node *temp = start;
	new = malloc(sizeof(struct node));
	new -> n = num;
	new -> link = NULL;
	if( start == NULL)
	{
		start = new;
		return 0;
	}
	while (temp ->link != NULL)
	{
		temp = temp ->link;
	}
	temp ->link = new;
	return 0 ;
}

 void display(struct node *strat)
{
	struct node *d;
	if( start == NULL)
	{
		printf("list is empty");
	}
	d = start;
	printf("list is\n");
	while ( d != NULL)
	{
		printf("%d\n",d -> n);
		printf("------->adres:%u\n",d);
		d = d->link;
	}
	printf("\n");
}
struct node* revers_list(struct node* start)
{
		printf("------->start%u\n------->start->n:%d",start,start->n);
	struct node* next,*prev=NULL,*ptr=start;
	//struct node *prev = NULL;
	//struct node *ptr = start;
	while(ptr != NULL)
	{
		next = ptr -> link;
	//	printf("------->next%u\n------->next->n:%d",next,next ->n);
		ptr->link = prev;
	//	printf("------->ptr->%u\n------->ptr->link->n:%d",ptr->link,ptr->link->n);
		prev = ptr;
	//	printf("------->prev%u\n------->prev->n:%d",prev,prev->n);
		ptr = next;
	//	printf("------->ptr%u\n------->ptr->n:%d",ptr,ptr->n);
	}
	start = prev;
		printf("------->start%u\n------->start->n:%d",start,start->n);
	return start;
}
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
//	printf("before revers the linked list\n");
	display(start);
	start = revers_list( start );
	display(start);
}


