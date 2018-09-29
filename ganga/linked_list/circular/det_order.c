#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

struct node *header = NULL;
main()
{
	//int a[] = { 4, 3, 2, 1, 0};
	//int a[] = { 2, 2, 2, 2, 2};
	int a[] = { 2, 4, 6, 8, 9};
	addnode(a[0]);
	addnode(a[1]);
	addnode(a[2]);
	addnode(a[3]);
	addnode(a[4]);
	display();
	det_order(&a[0]);
}

int addnode(int n)
{
	struct node *new = NULL, *temp = NULL;
	new = (struct node *)malloc(sizeof(struct node));

	new -> num = n;
	new -> next = NULL;

	if( header == NULL)
	{
		header = new;
		new -> next = header;
		return 0;
	}
	for( temp = header; temp -> next != header; temp = temp -> next);
	temp -> next = new;

	if(new -> next == NULL)
		new -> next = header;	
}

int display()
{
	struct node *temp = NULL;
	for( temp = header; temp; temp = temp -> next)
	{
		printf("%d  ", temp -> num);
		printf("%p  ", temp);
		printf("%p  ", temp -> next);

		if( temp -> next == header)
			temp -> next = NULL;
	}
	printf("\n");
}

int det_order(int *pass)
{
	printf("%p\n", pass);
	printf("%d\n", *pass);
}

/*
int det_order(int *pass)
{
	struct node *temp = NULL,*prev, *cur, *a, *b, *c, *d, *e;
	int i = 0, flag = 1;

	for(cur = header -> next, i = 1 ; cur ; cur = cur -> next, i++)
	{
		if(cur -> num == header -> num)
		{
			flag++;
		}
	}
	if( i == flag)
	{
		printf("not possible to sort out\n");
		return 0;
	}
	
	printf("%p\n", pass);
	printf("%d\n", *pass);
	for( temp = header; temp != header; temp = temp -> next)
	{
		if( (temp == pass) && (temp -> next == header))
		{
			printf("hi\n");
			if( pass -> num < a -> num)
			{
				printf("Ascending\n");
				return 0;
			}
			else
			{
				printf("Descending\n");
				return 0;
			}
		}
		else
		{
			if(pass -> num < a -> num)
			{
				printf("Ascending\n");
				return 0;
			}
			else
			{
				printf("Descending\n");
				return 0;
			}
		}
	}
}
*/
