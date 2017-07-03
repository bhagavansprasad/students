#define MAX 5
#include <stdio.h>
int top=-1 ;
int stack[MAX];
void push();
void pop();
main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	printf("\n---------\n");
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	printf("\n");
}
void push(int n)
{
	if(top==MAX-1)
	{
		printf("\nstack is full");
	}
	else
	{
		top++;
		stack[top]=n;
		printf("%d ",stack[top]);
	}

}


