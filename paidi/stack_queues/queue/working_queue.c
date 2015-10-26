#include <stdio.h>
#define MAX 4

int queue[MAX];

int  rear=-1, front=-1, item=0, i=0;

int get()
{

	if(front == -1)
		printf("queue is empty\n");
	else
	{
		item = queue[front];
		if (front == rear)
		{
			front = -1;
			rear  = -1;
		}
		else
			front++;

		return item;
	}


}

void put(int item)
{
	if(MAX == rear)
		printf("queue is full\n");
	else
	{
		if(rear == -1 && front== -1)
		{
			rear = 0;
			front= 0;
		}
		else
			rear++;

		queue[rear] = item;
		printf("insert  |%d|\n",queue[rear]);
	}
}

disply()
{
	if(front == -1)
	{
		printf("queue is empty\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
			printf("pending --%d\n",queue[i]);
	}
}
main()
{
	int retval=0;
	put(10);
	put(20);
	put(30);
	put(40);

	retval = get();
	printf("get val---> %d\n",retval);

	retval = get();
	printf("get val---> %d\n",retval);

	put(60);
	get();
	get();
	get();
	get();
	get();
	get();
	disply();
	return 0;

	retval = get();
	printf("get val---> %d\n",retval);
	insert(70);
	disply();

	retval = get();
	printf("get val---> %d\n",retval);
	disply();

	retval = get();
	printf("get val---> %d\n",retval);
	disply();

	retval = get();
	printf("get val---> %d\n",retval);
	disply();

	retval = get();
	printf("get val---> %d\n",retval);
	disply();

	retval = get();
	printf("get val---> %d\n",retval);
	disply();
}
