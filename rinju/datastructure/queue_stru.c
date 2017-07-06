#include<stdio.h>
#define MAX 10
typedef struct queue
{
	int arr[MAX];
	int front;
	int end;
}queue1;
queue1 c;
void display()
{
	int i;
		for(i=c.front;i<=0;i--)
		{
			printf(" %d ",c.arr[i]);
		}

}

void delete_queue()
{
if(c.front == c.end)
printf(" queue underflow");
else
{
printf(" delete item=%d ",c.arr[c.end]);
c.end++;
printf("array= %d ",c.arr[c.end]);
}

}
void insert_queue(int n)
{
	if(c.end == MAX-1)
		printf("queue is overflow\n");

	else

	{
		c.arr[c.front]=n;
			printf(" %d ",c.arr[c.front]);
		c.front++;
	}
}
main()
{
c.front = 0;
c.end = 0;
insert_queue(4);
insert_queue(6);
delete_queue();
display();
}


