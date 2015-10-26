#include "stdio.h"
#define MAX 10

void display (int *a,int n);
void bubble  (int *a,int x);

main()
{
	int a[MAX] = { 9,8,7,6,5,4,3,2,1,10};
	int i; 

	printf("Before soring\r\n");
	display(a,10);

	bubble(a,10);

	printf("After soring\r\n");
	display(a,10);
}

void display(int *a, int n)
{
	int  j;

	for(j = 0; j < n; j++)
		printf("%-5d", a[j]);

	printf("\r\n");
}

//Sort the array by using the bubble sort
void bubble  (int *a, int x)
{
	int  i,j,temp=0;

	for(i=0;i<x;i++)
	{
		for(j=0;j<x-1;j++)
		{
			if(a[j]>=a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				printf("%d-%d -->", i, j);
				display(a, 10);
			}
		}
	}
}


