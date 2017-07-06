#include<stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct queue
{
	int arr[MAX];
	int front;
	int end;
}queue1;
queue1 c;
void insert_queue(int n)
{
	if((c.front == 0 && c.end == MAX-1) || c.front ==c.end +1)
	{
		printf("queue overflow");
	}
	else if(c.front == -1) 

	{
		c.front =0;
		c.end = 0;
		c.arr[c.end]=n;
	} 
	else if(c.end == MAX-1 && c.front >0)
	{
		c.end = 0;
		c.arr[c.end] = n;
	}

	else
	{
		c.end++;
		c.arr[c.end]= n;
	}
}
void dq()
{
	if(c.front == -1 )
		printf("queue is empty");

	int data = c.arr[c.front];
	if(c.front == c.end)
	{
		c.front = -1;
		c.end = -1;
	}
	else if(c.front == MAX-1)
	{
		c.front = 0;
	}
	else
		c.front++;

printf("\ndelete item = %d",data);
}

void display_queue()
{
	int i;
	if(c.end >= c.front)
	{
		for(i = c.front; i<= c.end; i++)
			printf(" %d ",c.arr[i]);
	}
	else
	{
		for(i=c.front;i < MAX-1;i++)
		{
			printf(" %d ",c.arr[i]);
		}
		for(i = 0;i<=c.end ; i++)
		printf(" %d ",c.arr[i]);
	}
}
main()
{
	c.front = -1;
	c.end = -1;
	insert_queue(4);
	insert_queue(7);
	insert_queue(8);
	display_queue();
	dq();
	printf("\nafter delete:");
	insert_queue(99);
	insert_queue(9);
	display_queue();
}
