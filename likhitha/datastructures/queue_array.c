#include<stdio.h>
#define max 5
int rear=-1 , front=-1;
int queue[max];
void enqueue();
void dequeue();
main()
{
	enqueue(7);
	enqueue(3);
	enqueue(9);
	printf("\n");
	dequeue();
}
void enqueue(int n)
{
	if(rear==(max-1))
	{
		printf("queue is full\n");
	}
	else
	{
		rear++;
		queue[rear]=n;
		printf("%d ",queue[rear]);
	}
}
void dequeue()
{
	if(front==rear)
	{
		printf("queue is empty\n");
	}
	else
	{
		front++;
		printf("%d\n",queue[front]);
	}
}
