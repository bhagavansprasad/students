#include<stdio.h>
#define MAX 10
	int queue[MAX];
	int end = 0,front = 0;
		void queue_insert(int n)
		{
		if(end == MAX)
		printf("over flow");

		else
		queue[front]= n;
		printf(" %d\n ",queue[front]);
		front++;

		}

		void queue_delete(void)
		{
				if(front == end)
				printf(" queue is empty:  ");

				else
				printf(" %d ",queue[end]);
			//	queue[end]=queue[end+1];
		end++;
				

		}
main()
{
	int i;
	queue_insert(8);
	queue_insert(23);
	queue_insert(17);
	queue_insert(67);
	queue_insert(27);
	queue_insert(98);
	queue_delete();
	queue_delete();

	printf("after delete :");
	for(i=end;i<front;i++)
	printf(" %d ",queue[i]);
}
