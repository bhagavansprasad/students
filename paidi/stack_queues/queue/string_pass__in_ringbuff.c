#include <stdio.h>
#define MAX 6

char *buffer1[MAX];

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
	printf("string Enter-- = <%s>\n",n);
	//	printf("rear1--->%d,max--->%d\n",rear,MAX);
	int retrn = 0;
	if(MAX == rear)
	{
		printf(">> buffer1 is full <<\n");
		retrn = delet_number();
		printf("delet string--->=%s\n",retrn);
		if(rear == MAX)
		{
			rear--;
			//printf("rear2--->%d,max--->%d\n",rear,MAX);
		}
		buffer1[rear] = n;
		//printf("rear3--->%d,max--->%d\n",rear,MAX);
		printf("insert buffer  = |%s|\n\n",buffer1[rear]);
		rear++;
	}
	else
	{
		if(rear == -1 && front== -1)
		{
			rear = 0;
			front= 0;
			//printf("rear4--->%d,max--->%d\n",rear,MAX);
		}
		else
			rear++;

		// printf("rear5--->%d,max--->%d\n",rear,MAX);
		//printf("valu-->=%s\n",n);
		buffer1[rear] = n;
		printf("Insert Buffer  = |%s|\n\n",buffer1[rear]);
	}
}

void main()
{
	int i;
	char *array[50]= {"paid","aura","network","good","institute","may","jun","ravi","pream","sudhakar","Eswar"};
	for(i=0; array[i]!='\0'; i++)
	{
		//printf("variables= %s\n",array[i]);
		add_buffer(array[i]);
	}
}
