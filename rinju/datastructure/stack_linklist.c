#include<stdio.h>
#define MAX 5
typedef struct stack
{
	int arr[MAX];
	int top;
}stck;

stck d;
void display()
{
	int i; 

	for(i=d.top;i>=0;i--)
	{
		printf("%d ",d.arr[i]);

	}
	printf("\n");
}
void pop()
{
	int i;
	if(d.top==-1)
		printf("stack is underflow\n");
	else
	{
		printf("popped element=%d ",d.arr[d.top]);
		d.top--;
	}
} 
void push(int n)
{

	if(d.top == MAX-1)
		printf("stack is overflow\n");
	else
	{ 
		d.top+=1; 
		d.arr[d.top]=n;
	}
	}
main()
{
	d.top=-1;

	push(4);
	push(6);
	push(8);
	push(10);
	push(9);
	push(19);
	display();
	pop();
   pop();
   display();
   //pop();
  }
