# include<stdio.h>
#include <stdlib.h>

struct node 
{
	int n;
	struct node *p;	
};
struct node *new;
struct node *h = NULL;
main()
{
//	struct node *d;
	add(10);
	add(20);
	add(30);
	add(40);
	display();

}


int add( int num)
{
	struct node *temp = h;
	new = malloc(sizeof(struct node));
	new -> n = num;
	new -> p = NULL;
	if( h == NULL)
	{
		h = new;
		return 0;
	}
	while (temp ->p != NULL)
	{
		temp = temp ->p;
	}
	temp ->p = new;
	return 0 ;
}

int display()
		{
		struct node *d;
		if( h == NULL)
		{
		printf("list is empty");
		}
		d = h;
		printf("list is\n");
		while 
		( d != NULL)
		{
		printf("%d\n",d -> n);
		printf("------->adres:%u\n",d);
		d = d->p;
		}
		printf("\n");
		}

