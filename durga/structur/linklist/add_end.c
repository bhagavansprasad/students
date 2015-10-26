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
	while( d != NULL)
		{
			printf("%d\n",d -> n);
			printf("------->adres:%u\n",d);
			d = d->link;
		}
	printf("\n");
}
struct node* add_end(struct node *start, int num)
{
	struct node *temp,*p;

	temp = (struct node*)malloc(sizeof(struct node));
    temp->n = num;
	p = start;
	while(p->link !=NULL)
           p = p->link;
	p->link = temp;
	temp->link = NULL;
	return start;

}
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	add_end(start,50);
	display();

}

