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
	struct node* i, *j, *k;
	int a;
	k = start;
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

	for ( i = k; i != NULL; i = i ->link)
	{
		for (j = i->link; j !=NULL; j = j ->link)
		{
			if ( i->n > j ->n)
			{
				a = i ->n;
				i->n = j ->n;
				j->n = a;
			}
		}
	}
	return 0;
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
main()
{
add(5);
add(20);
add(40);
add(50);
add(30);
add(3);
add(7);
add(1);
display();
}
