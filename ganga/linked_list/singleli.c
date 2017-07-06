#include <stdio.h>
#include "defs.h"
#include "stdlib.h"

struct node *header = NULL;
main()
{
	addnode(7);
	addnode(6);
	addnode(5);
	printf("inserting nodes:\n");
	display();
	insert_at_begin(4);
	printf("inserting node at begin:\n");
	display();
	delete_by_val(7);	
	printf("inserting nodes:\n");
	display();
	insert_at_end(9);
	printf("inserting node at end:\n");
	display();
	insert_by_pos(8,4);
	printf("insert node by position:\n");
	display();
	orderded_insert(2);
	//orderded_insert(6);
	//orderded_insert(7);
	//orderded_insert(5);
	printf("ordered inserting nodes:\n");
	display();
}

int addnode(int n)
{
	struct node *temp = NULL, *new = NULL;
	new = (struct node *)malloc(sizeof(struct node));

	new->num = n;
	new->next = NULL;

	if(header == NULL)
	{
		header = new;
		return; 
	}

	for(temp = header; temp->next != NULL; temp = temp->next);
	temp->next = new;

	return 0;
}

int insert_at_begin(int n)
{
	struct node *temp = NULL, *new;
	new = (struct node*)malloc(sizeof(struct node));

	new -> num = n;
	temp = header;
	header = new;
	new -> next = temp;
}

int insert_at_end(int n)
{
	struct node *temp = NULL, *new;
	new = (struct node*)malloc(sizeof(struct node));

	new -> num = n;
	new -> next = NULL;

	for(temp = header ; temp != NULL; temp = temp->next)
	{
		if(temp -> next == NULL)
		{
			temp -> next = new;
			return;
		}
	}
}

int insert_by_pos(int n, int pos)
{
	int i;
	struct node *temp = NULL, *new;
	new = (struct node*)malloc(sizeof(struct node));

	new -> num = n;
	new -> next = NULL;

	for(i = 1, temp = header ; temp -> next != NULL;  temp = temp -> next, i++)
	{
		if(pos == 1)
		{
			temp = header;
			header = new;
			new -> next = temp;
			return;
		}

		else if(i == pos - 1)
		{
			new -> next = temp -> next;
			temp -> next = new;
			return;
		}
	}
}

int orderded_insert(int n)
{
	struct node *temp, *c, *new;
	new = (struct node*)malloc(sizeof(struct node));

	new -> num = n;
	new -> next = NULL;

	if(header == NULL)
	{
		header = new;
		return;
	}

	for(temp = header ; temp -> next != NULL; temp = temp->next)
	{
		if(new -> num >= temp -> num)
			temp -> next = new;

		else if(new -> num < header -> num) 
			new -> next = header;

		else
		{
			temp = header -> next;
			for(c = header; c != NULL; c = temp, temp = temp -> next)
			{
				c -> next = new;
				new -> next = temp;
			}
		}
	}
	return 0;
}

int delete_by_val(int n)
{
	struct node *temp = NULL, *prev = NULL;

	for(temp = header; temp != NULL; prev = temp, temp = temp -> next)
	{
		if(temp -> num == n)
		{
			if(temp == header)
			{
				header = temp -> next;
				return;
			}

			else
			{
				prev->next = temp->next;
				return;
			}
		}
	}
}

int display()
{
	struct node *temp = NULL;

	for(temp = header; temp != NULL; temp = temp->next)
	{
		printf("%d  ", temp->num);
	}
	printf("\n");
}
