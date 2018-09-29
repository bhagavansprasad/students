#include "structure.h"
#include "declaration.h"

struct node *start = NULL;

int main()
{
	addnode(10);
	addnode(40);
	addnode(30);
	addnode(45);
	addnode(100);

	display();

	search_value(40);
	search_value(100);
	search_value(200);

	return 0;
}

int addnode(int value)
{
	struct node *new, *temp;
	new = malloc(sizeof(struct node));

	new -> value = value;
	new -> link = NULL;

	if(start == NULL)
	{
		start = new;
		return 0;
	}
	temp = start;
	while(temp->link != NULL)
	{
		temp = temp -> link;
	}
	temp-> link = new;
	return 0;
}

void display(void)
{
	struct node *temp = start;
	int c =0;
	if(start == NULL)
	{
		printf("no nodes available in linked list\n");
	}
	while(temp != NULL)
	{
		c++;
		printf("NODE %d ----> %d %10p  %10p\n",c,temp -> value, temp ->link ,temp);
		temp = temp -> link;
	}
}

int search_value(int value)
{
	struct node *temp = start;
	int c = 0;
	if(start == NULL)
	{
		printf("no nodes are available in the list \n");
		return 0;
	}
	while(temp != NULL)
	{
		c++;
		if(temp -> value == value)
		{
			printf("%d value is found at node %d\n", value, c);
			return 0;
		}
		if(temp -> link == NULL)
		{
			printf("%d value is not found in the list\n", value);
		}
		temp = temp->link;
	}
}
