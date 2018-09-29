#include <stdio.h>
#define max 5
struct queue{
	int rear;
	int front;
	int queue[max];
};
void push();
void pop();

struct queue s;
main()
{
	s.rear=-1;
	s.front=-1;
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	printf("\n");
	pop();
	pop();
	printf("\n");
}

void push(int n)
{
	if(s.rear==max-1)
	{
		printf("queue is full\n");
	}
	else
	{
		s.rear++;
		s.queue[s.rear]=n;
		printf("%d ",s.queue[s.rear]);
	}
}

void pop()
{
	if(s.front==s.rear)
	{
		printf("queue is empty\n");
	}
	else
	{
		s.front++;
		printf("%d ",s.queue[s.front]);

	}
}
