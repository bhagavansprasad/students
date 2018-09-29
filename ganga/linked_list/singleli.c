#include <stdio.h>
#include "stdlib.h"
#include "defs.h"

struct node *header = NULL;
main()
{
	addnode(7);
	addnode(6);
	addnode(6);
	addnode(6);
	addnode(5);
	addnode(6);
	addnode(6);
	addnode(5);
	addnode(6);
	printf("inserting nodes:\n");
	display();

	insert_at_begin(4);
	printf("inserting node at begin:\n");
	display();

	delete_by_val(7);	
	printf("inserting nodes:\n");
	display();

	delete_by_pos(3);	
	printf("inserting nodes:\n");
	display();

	insert_at_end(9);
	printf("inserting node at end:\n");
	display();

	insert_by_pos(8,3);
	printf("insert node by position:\n");
	display();

	printf("ordered inserting nodes:\n");
	display();

	modify_by_value(5, 7);
	printf(" modifing inserting nodes:\n");
	display();

	node_count();
	count(6);
	getnth(3);
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

int modify_by_value(int n , int number)
{
	struct node *temp = NULL;
	for(temp = header; temp -> next != NULL; temp = temp -> next)
	{
		if( temp -> num == n)
		{
			temp -> num = number;
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

int delete_by_pos(int pos)
{
	int i;
	struct node *temp, *prev;
	for(temp = header, i = 1 ; temp != NULL;  prev = temp, temp = temp -> next, i++)
	{
		if(pos == 1)
		{
			header = temp -> next;
			return;
		}

		else if( i = pos -1)
		{
			prev -> next = temp -> next;
			return;
		}
	}
}


int display()
{
	struct node *temp = NULL;

	for(temp = header; temp != NULL; temp = temp->next)
	{
		printf("%d  ", temp->num);
		//printf("%p  ", temp->next);
	}
	printf("\n");
}

int node_count()
{
	int i;
	struct node *temp = NULL;

	for(i = 0,temp = header; temp != NULL; temp = temp->next, i++);

	printf("count of the nodes are %d\n", i);

	return 0;
}

int count(int n)
{
	int count = 1;
	struct node *temp = NULL;

	for(temp = header ; temp != NULL; temp = temp -> next)
	{
		if( n == temp -> num)
			count++;
	}
	printf("the node value %d is occured in :%d times\n", n, count);
}

int getnth(int index)
{
	int i;
	struct node *temp = NULL;

	for( i = 0, temp = header; temp != NULL; temp = temp -> next, i++)
	{
		if (i == index)
		{
			printf("%d rd postion value   : %d\n", index, temp -> num);
			printf("%d rd postion address : %p\n", index, temp -> next);
		}
	}
}
