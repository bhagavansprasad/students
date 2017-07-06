#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *link;

}stack1;
stack1 *head =NULL; 
void display()
{
	stack1 *c =head;
	while(c != NULL)
	{
		printf(" %d ",c->data);
		c=c->link;
	}

}

void delete_stack()
{
	stack1 *c = NULL;
	stack1 *temp = head;

	while(temp->link != NULL)
	{
	c=temp;
	temp = temp->link;
	}
	
		c->link = NULL;
	

}
void insert_stack(int n)
{
	stack1 *temp =NULL;
	stack1 *c =NULL;
	c = malloc(sizeof(stack1));
	c->data=n;
	c->link=NULL;
	if(head == NULL)
	{
		head =c;
	}
	else
	{ temp =head;
		while(temp->link != NULL)
		{
			temp= temp->link;
		}
		temp->link = c;

	}
}
main()
{


	insert_stack(4);
	insert_stack(46);
	insert_stack(64);
	insert_stack(42);
	insert_stack(14);
display();
delete_stack();
display();
}


