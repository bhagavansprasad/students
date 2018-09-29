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

int display(struct node * start)
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
struct node* delet_node(struct node* start, int item)
{
	struct node *p, *temp ;
	if(start == NULL)
	{
		printf("list is empty\n");
		return start;
	}
		temp = start;
	if(temp->n == item)
	{
		start = temp->link;
		free(temp);
		
		return start;
	}
	p = start;
	while( p->link != NULL)
	{
		if(p->link->n == item)
		{
			temp = p->link;
			p->link = temp->link;
			free(temp);
			return start;
		}
		p = p->link;
	}
	printf("item is not found\n");
	return start;
}
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	start = delet_node(start,10);
	display(start);

}


