#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *top = NULL;

void push(int x)
{
	NODE *new = malloc(sizeof(NODE));

	new->data = x;
	new->next = top;

	top = new;
}

int pop()
{
	int rvalue;
	NODE *temp;

	if(top == NULL)
	{
		printf("stack is empty\n");
		return 0;
	}
	else
		temp = top;

	rvalue = temp->data;
	top = temp->next;
	free(temp);

	return rvalue;
}

void disply()
{
	NODE *temp;

	if(top == NULL)
		printf("STACK IS emty\n");
	else
	{
		for(temp = top;temp!= NULL;temp = temp->next)
		{
			printf("|%d|\n",temp->data);
		}
		printf("\n top element = %d\n",top->data);
	}
}

main()
{
	int retval = 0;
	push(1);
	push(2);
	push(3);
	disply();
	printf("pop  :%d\n", pop());
	printf("pop  :%d\n", pop());
	printf("pop  :%d\n", pop());
	disply();
	printf("pop  :%d\n", pop());
	printf("pop  :%d\n", pop());
	printf("pop  :%d\n", pop());
	push(6);
	push(9);
	printf("pop  :%d\n", pop());
	printf("pop  :%d\n", pop());
	printf("pop  :%d\n", pop());
	disply();
	return 0;

	printf("poped value  |%d|\n",pop());
	printf("poped value  |%d|\n",pop());
	printf("poped value  |%d|\n",pop());
	push(10);
	printf("poped value  |%d|\n",pop());
	disply();
	printf("poped value  |%d|\n",pop());
	printf("poped value  |%d|\n",pop());
	printf("poped value  |%d|\n",pop());
	printf("poped value  |%d|\n",pop());
	printf("poped value  |%d|\n",pop());
	printf("poped value  |%d|\n",pop());
	disply();
	return 0;
	push(4);
	push(5);
	push(6);
	retval = pop();
	printf("pop  |%d|\n",retval);
	disply();
	retval = pop();
	printf("pop  |%d|\n",retval);
	disply();
	retval = pop();
	printf("pop  |%d|\n",retval);
	disply();
	retval = pop();
	printf("pop  |%d|\n",retval);
	disply();
	retval = pop();
	printf("pop  |%d|\n",retval);
	disply();
	retval = pop();
	printf("pop  |%d|\n",retval);
	disply();
	push(15);
	push(25);
	push(35);
	disply();
	retval = pop();
	printf("pop  |%d|\n",retval);
	printf("pop  |%d|\n",retval);
	disply();
	return 0;
	push(45);
	push(55);
	push(65);
	disply();
}
