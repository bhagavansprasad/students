#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int data;
	struct queue *link;

}queue1;
queue1 *head =NULL; 
void display()
{
	queue1 *c =head;
	while(c != NULL)
	{
		printf(" %d ",c->data);
		c=c->link;
	}

}

void delete_queue()
{
	queue1 *c = NULL;
	//queue1 *temp = head;

	if(head != NULL)
	{c= head;
		head = head->link;
		free(c);
	}

}
void insert_queue(int n)
{
	queue1 *temp =NULL;
	queue1 *c =NULL;
	c = malloc(sizeof(queue1));
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


	insert_queue(4);
	insert_queue(6);
	insert_queue(9);
	insert_queue(7);
	insert_queue(89);
	insert_queue(23);
display();
delete_queue();
delete_queue();
display();
}


