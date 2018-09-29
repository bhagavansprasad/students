#include<stdio.h>
#include<stdlib.h>

#define size 5
int stack[size];
int top=-1;

int stfull() 
{
	if (top >= size)
		return 1;
	else
		return 0;
}

void push(int *spush,int item)
{
	spush[++top]= item;
	spush++;
}

int stempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int pop(int *spop) 
{
	int item;
	item = spop[top];
	top--;
	return (item);
}

void display() 
{
	int i;
	if (stempty())
		printf("\nStack Is Empty!");
	else 
	{
		for (i = top; i >= 0; i--)
			printf("\n%d", stack[i]);
	}
}

int main() 
{
	int item, choice,i;

		printf("\n\tImplementation Of Stack");
		printf("\nMain Menu");
		printf("\nPush \nPop \nDisplay \n");
				
				for(i=0;i<size;i++)
				{
				printf("\nEnter The item to be pushed");
				scanf("%d", &item);
				if (stfull())
					printf("\nStack is Full!");
				else
					push(stack,item);
				}
				for(i=0;i<size;i++)
				{
				display();
				}
				
				for(i=0;i<size;i++)
				{
				if (stempty())
					printf("\nEmpty stack!Underflow !!");
				else 
				{
					item = pop(stack);
					printf("\nThe popped element is %d", item);
				}
}
				for(i=0;i<size;i++)
				{
				display();
				}

	return 0;
}
