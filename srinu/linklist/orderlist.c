#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int no;
	struct node *next;	
};
//struct node *new;
struct node *h = NULL;


int add( int num)
{
	struct node *temp = h;
	struct node* i, *j, *k;
	int a;
	k = h;
struct node *new;
	new = malloc(sizeof(struct node));
	new -> no = num;
	new -> next = NULL;
	if( h == NULL)
	{
		h = new;
		return 0;
	}
	while (temp ->next != NULL)
	{
		temp = temp ->next;
	}
	temp ->next = new;

	for ( i = k; i != NULL; i = i ->next)
	{
		for (j = i->next; j !=NULL; j = j ->next)
		{
			if ( i->no > j ->no)
			{
				a = i ->no;
				i->no = j ->no;
				j->no = a;
			}
		}
	}
	return 0;
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
		while ( d != NULL)
		{
			printf("%d\n",d -> no);
			printf("------->adres:%p\n",d);
			d = d->next;
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
