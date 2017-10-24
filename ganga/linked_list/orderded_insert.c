#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

struct node *header = NULL;
int main()
{
	addnode(10);
	addnode(90);
	addnode(20);
	addnode(40);
	addnode(6);
	addnode(50);
	addnode(1);
	addnode(100);
	display();
}

int addnode(int n)
{
	struct node *temp = NULL;
	struct node *new = NULL;
	struct node *c = NULL;
	new = malloc(sizeof(struct node));
	new -> num = n;
	new -> next = NULL;

	if(header == NULL)
	{
		header = new;
		return 0;
	}

	if(new -> num < header -> num)
	{
		new -> next = header;
		header = new;
	}
	
	for( temp = header, c = header -> next; temp -> next != NULL; temp = c, c = temp -> next)
	{
		if(new -> num < c -> num)
		{ 
			temp -> next = new;
			new -> next = c;
			return 0;
		}
	}

	if(new -> num >= temp -> num)
		temp -> next = new;
	return 0;
}

int display()
{
	struct node *temp;
	for(temp = header; temp != NULL; temp = temp -> next)
	{
		printf("%d\n", temp -> num);
	}
}
