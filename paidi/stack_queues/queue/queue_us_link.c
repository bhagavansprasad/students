#include<stdio.h>
#include <stdlib.h>
void push(int);

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *front = NULL, *rear = NULL;
int value;

int pop()
{
	NODE *temp;

	if(front == NULL)
	{
		printf("queue is empty\n");
		return 0;
	}
	else
	{
		temp = front;
		value = front->data;
		front = front->next;
		free(temp);


		if(front == NULL)
			rear = NULL;
		return value;
	}

}

void push(int x)
{
	NODE *new ;
	new = malloc(sizeof(NODE));
	new->data = x;

	if(rear == NULL)
	{
		rear = new;
		rear->next = NULL;
		front= rear;
	}
	else
	{
		rear->next = new;
		rear = new;
		rear->next = NULL;
	}
}
void display()
{
	NODE *temp ;
	if(rear == NULL)
		printf("Queue is empty\n");
	else
	{
		for(temp = front;temp !=NULL;temp=temp->next)
		{
			printf("|%d|\n",temp->data);
		}
	}
}
main()
{
	int retval = 0;
	push(10);
	push(20);
	push(30);
	push(40);
	display();
	printf("pop--->%d\n",pop());
	push(50);
	display();
	printf("pop--->%d\n",pop());
	printf("pop--->%d\n",pop());
	printf("pop--->%d\n",pop());
	push(60);
	display();
	printf("pop--->%d\n",pop());
	printf("pop--->%d\n",pop());
	display();
	push(70);
	push(80);
	printf("pop--->%d\n",pop());
	printf("pop--->%d\n",pop());
	printf("pop--->%d\n",pop());
	push(70);
	printf("pop--->%d\n",pop());
	push(80);
	printf("pop--->%d\n",pop());
	printf("pop--->%d\n",pop());
	printf("pop--->%d\n",pop());
	printf("pop--->%d\n",pop());
	display();
	return 0;
	printf("pop--->%d\n",pop());
	display();
	printf("pop--->%d\n",pop());
	display();
	printf("pop--->%d\n",pop());
	display();
	printf("pop--->%d\n",pop());
	display();
}

