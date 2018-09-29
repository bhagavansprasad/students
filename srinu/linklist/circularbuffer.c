#include <stdio.h>
#define MAX 4
typedef struct
{
	char string[10];
}strng;

int buffer1[MAX];

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
	//printf("string>>>>\n");
	printf("string -->=%c\n",*n);
//	printf("string %d\n",*n);
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
	        printf("enter>>>>\n");
			rear = 0;
			front= 0;
		}
		else
			rear++;

		buffer1[rear] = *n;
		printf("string insert  |%c|\n",buffer1[rear]);
		//printf("string insert  |%d|\n",buffer1[rear]);
	}
}

disply()
{
	if(front == -1)
	{
		printf("buffer1 is empty\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
			printf("pending --%d\n",buffer1[i]);
	}
}

void main()
{
	//printf("enter\n");
	int i;
	char array[20]= {'a','b','c','d','e','f','g','h','i','j','k','\0'};
	//printf("enter\n");
	//char buff[MAX];
	for(i=0; array[i]!='\0'; i++)
	{
	//printf("enter******\n");
//	printf("variables= %c\n",array[i]);
   	add_buffer(&array[i]);
	}


}
