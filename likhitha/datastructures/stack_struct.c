#include <stdio.h>
#define max 5
struct stack{
	int top;
	int stack[max];
};
void push();
void pop();

struct stack s;
main()
{
	s.top=-1;
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	printf("\n");
	pop();
	pop();
	printf("\n");
}

void push(int n)
{
	if(s.top==max-1)
	{
		printf("stack is full\n");
	}
	else
	{
		s.top++;
		s.stack[s.top]=n;
		printf("%d ",s.stack[s.top]);
	}
}

void pop()
{
	if(s.top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("%d ",s.stack[s.top]);
		s.top--;
	}
}
