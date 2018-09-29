#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int top = 0;
int stack[MAX];

void push(int n)
{
	if(MAX == top)
	{
		printf("stack is full\n");
	}
	else
	{
		stack[top] = n;
		printf("|%d|\n",stack[top]);
		top++;
	}
}
int pop(void)
{
    top--;
	if(stack[top] == -1 )
	{
	   printf("stack is empty\n");
	   top = 0;
	   return 0;
	}
	return stack[top];
}

void dump_stack(void)
{	
	int i;
	for(i=*stack;i<top;i++)
	{
		printf("|%d|",stack[i]);
	}
	printf("\n");
}

main()
{
    int val = 0;
	push(10);
	push(30);
	push(5);

	push(9);
	dump_stack();

	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);

	push(100);
	dump_stack();

	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);

	push(200);
	push(300);
	push(400);
	push(500);
	dump_stack();
	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);
    return 0;
	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);

	val = pop();
	printf("-->popped value :%d\n", val);
	push(10);
	push(12);
	push(13);
	push(14);
	push(15);
	push(16);
	push(17);
	dump_stack();
}
