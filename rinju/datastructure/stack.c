#include<stdio.h>
#define MAX 5
int top = -1;
int stack[MAX];
void push(int n)
{
	if(MAX == top)
	printf("stack is full");
	
	else
	top++;
	stack[top]=n;
	printf(" %d ",stack[top]);
}

void pop(void)
{
	if(top == -1)
	printf("stack is empty ");

	else
	printf(" \n%d ",stack[top]);
	top--;
	
}

main()
{
int i;
	push(7);
	push(3);
	push(9);
	push(45);
	push(68);
	push(78);
	//push(82);

	pop();
	pop();

	printf("\nafter pop\n");
	for(i=0;i<MAX;i++)
	printf(" %d ",stack[i]);
}
