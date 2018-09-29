#include <stdio.h>
#include <stdlib.h>
#define MAX 3
static int stack[MAX];
static int top = 0;
int i=0;
int f = 0;

int pop(int *arr)
{
	int b=0;

	if(MAX == top) 
	{
		printf("stck is empty\n");
	}
	else
	{
		if(top <= f)
		{	   
			printf("stack is empty\n");
			if(top<1)
			top++;
		}
		else
		{
			for(i=0;i<top;i++)
			{
				b = arr[i];	
			}

		}
	}
	top--;
	return b;
}

void dump_stack()
{
	for(i = 0; i<top ;i++)
	{
		printf("|%d| ",stack[i]);
	}
	printf("\n");
}

int push(int a)
{
	if(MAX != top)
	{
		stack[top]=a;
		top++;
	}
	else
	{
		printf("\nstack is full\n\n");
		return 0;
	}
}

main()
{
	int retval = 0;
	push(8);
	push(9);
	push(11);
	push(10);
	push(160);

	dump_stack();

	retval = pop(stack);
	printf("-->poped : %d	top	:%d\n", retval,top);

	retval = pop(stack);
	printf("-->poped :%d	top	:%d\n", retval,top);

	retval = pop(stack);
	printf("-->poped :%d	top	:%d\n", retval,top);
	dump_stack();
	return 0;

	dump_stack();

	retval = pop(stack);
	retval = pop(stack);
	retval = pop(stack);

	push(88);
	push(99);
	push(100);
	push(120);

	dump_stack();
	retval = pop(stack);
	printf("-->poped :%d	top	:%d\n", retval,top);
	dump_stack();
	retval = pop(stack);
	printf("-->poped :%d	top	:%d\n", retval,top);
	dump_stack();
	retval = pop(stack);
	printf("-->poped :%d	top	:%d\n", retval,top);
	dump_stack();
	retval = pop(stack);
	printf("-->poped :%d	top	:%d\n", retval,top);
	dump_stack();
	push(200);
	push(300);
	push(400);
	dump_stack();

	return 0;

}
