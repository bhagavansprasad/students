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
