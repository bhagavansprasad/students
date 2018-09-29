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
struct node* add_posin(struct node* start, int data,int pos)
{
	struct node *temp, *p;
	int i, c = 0;
	p = start;
	for (i = 1; i < pos-1&& p->link!=NULL; i++)
		p = p->link;
	if(p == NULL)
		printf("list is empty\n");
	else 
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->n = data;
		if(pos == 1)
		{
			temp->link = start;
			start = temp;
		}

		else
		{
			temp->link = p->link;
			p->link = temp;
		}
	}
	return start;
}
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	add_posin(start,35,3);
	display();

}
