#include <stdio.h>
#include <stdlib.h>
int addd_node(int ,int );
struct node
{
	int val;
	struct node *link;
};
struct node *head[2] = {NULL,NULL};
struct node *start = NULL;
/*function for creating two link lists*/

int addd_node(int n, int index)
{
	int h1 = index;
	struct node *new,*temp = head[h1];
	new = malloc(sizeof(struct node));
	new -> val = n;
	new -> link = NULL;
	if(head[h1] == NULL)
	{
		head[h1] = new;
		return 0;
	}
	while( temp -> link != NULL)
	temp = temp -> link;

	temp ->link = new;

//	new -> link = head[h1];
//	head[h1] = new;
	return 0;
}

/*function for result node creationt*/

int adding_node(int n)
{

	struct node *new, *temp = start;
	new = malloc(sizeof(struct node));
	new->val = n;
	new->link=NULL;
	if(start == NULL)
	{
		start = new;
		return 0;
	}
	new->link = start;
	start = new;
	return 0;
}

/*function for display*/

int display(struct node *head)
{
	struct node *t;
	for(t=head;t!=NULL;t=t->link)
	{
		printf("%5d ",t->val);
	}
	return 0;
}
/*function for get_key*/

/*int get_key(int size)
{
	if ( size <= 5)
		return 0;
	if(size > 5 && size <= 9)
		return 1;
}*/

int add_number_to_list(int value, int index)
{
	while(value != 0)
	{
		addd_node(value % 10, index);
		value = value / 10;
	}
}

main()
{
	int t, sum = 0, c = 0;

	int a = 4360;
	int b = 9456;

	add_number_to_list(a, 0);
	add_number_to_list(b, 1);

	display(head[0]);
	printf("\n");
	display(head[1]);
	
	printf("\n");
	while(head[0] != NULL)
	{
		t = head[0] ->val + head[1] ->val + c;
		sum = t %10;
		adding_node(sum);
		c = t/10;
		head[0] = head[0] ->link;
		head[1] = head[1] ->link;

	}
	printf("%d",c);
	display(start);
	printf("\n");
	exit(1);
}

