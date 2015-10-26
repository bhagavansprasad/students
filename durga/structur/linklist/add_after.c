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

int display()
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
struct node* add_after(struct node* start, int data,int item)
{
	struct node *temp, *p;
	p = start;
	while( p !=NULL)
	{
		if( p->n == item)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			temp->n = data;
			temp->link = p->link;
			p->link = temp;

	return start;
		}
		p = p->link;
	}
}

main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	add_after(start,35,30);
	display();

}

