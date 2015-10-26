#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int n;
	struct node *link;	
};
struct node *new;
struct node *start = NULL;
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	add_first(5);
	display();

}


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
	while 
		( d != NULL)
		{
			printf("%d\n",d -> n);
			printf("------->adres:%u\n",d);
			d = d->link;
		}
	printf("\n");
}
int add_first( int num)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->link = start;
	start = temp;
	temp->n = num;
}

