#include "stdio.h"

int push(int n);
int pop(void);

#define MAX_STACK_SIZE 4
int  t, n, i;
int top = 0;
int arr[] = {0};

int dump_stack()
{
	printf("stack top :%d-->", top);

	for(i = 0; i < top; i++)
		printf("%d ", arr[i]);
	
	printf("\n");
}
main()
{
	dump_stack();
	push(10);
	push(20);
	push(30);
	push(44);
	dump_stack();
	t = pop();
	t = pop();
	t = pop();
	dump_stack();
}

int push(int n)
{
	printf("push :%d value\n", n);

	if(top <= MAX_STACK_SIZE)
	{
		arr[top] = n;
		top++;
	}
	else
	{
		printf("stack is full\n");
	}
}

int pop(void)
{
	if(top > 0)
	{
		t = arr[top-1];
		top--;
		printf("popping :%d value\n", t);
		return t;
	}
	else
	{
		printf("stack is empty");
	}
}

