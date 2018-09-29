#include <stdio.h>
#define MAX 4
char buffer1[MAX];
int  rear=-1, front=-1, item=0, i=0;

int delet_number()
{
	if(front == -1)
		printf("buffer1 is empty\n");
	else
	{
		item = buffer1[front];
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

void add_buffer(char *n)
{
	printf("Enter char in Buffer-->=%c\n",*n);
	int retrn = 0;
	if(MAX == rear)
	{
		printf("buffer1 is full\n");
		retrn = delet_number();
		printf("delet val--->=%c\n",retrn);
	}
	else
	{
		if(rear == -1 && front== -1)
		{
			rear = 0;
			front= 0;
		}
		else
			rear++;
		buffer1[rear] = *n;
		printf("insert buffer  |%c|\n",buffer1[rear]);
	}
}

void main()
{
	int i;
	char array[20]= {'a','b','c','d','e','f','g','h','i','j','k','\0'};
	for(i=0; array[i]!='\0'; i++)
	{
		//	printf("variables= %c\n",array[i]);
		add_buffer(&array[i]);
	}
}
