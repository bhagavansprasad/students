#include "stdio.h"
#define MAX  5
int stack[MAX];
static int top = 0;
main()
{
		push(5);
		push(10);
		pop();
		push(15);
		push(20);
		push(25);
		pop();
		push(35);
		push(40);
		push(50);

}
int push (int n)
{
		if(MAX==top)
		{
			printf("the elements in the stack is full");
			printf("\n");
			return;
		}
		else
		{		
			stack[top]=n;
			printf("%d\n\n\n",stack[top]);
			
		}
	top++;
}		


int pop()
{
int i;
	if(top==-1)
	
	{
		printf("the elements in the list is empty");
		return;
	}
	else 
		
		for(i=0;i<top;i++)
		{
			stack[i]=stack[i+1];
		printf("moved element = %d\n\n",stack[i]);

		return;
		}
		top--;
	
//	printf("remove element = %d\n\n",stack[top]);
	printf("\n\n\n\n\n");
}

