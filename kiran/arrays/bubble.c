#include <stdio.h>

int main()
{
	int arr[10] = {6,100,34,56,76,3,8,2,2,4};
	int i = 0, j = 0, swap = 0, n = 10;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-1-i; j++)
		{
			if(arr[j] > arr[j+1])  /* >for assending order, < for dessending order*/
			{
				swap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = swap;
			}
		}
	}
	printf("after sorting the values are -----> ");
	for(i = 0; i < n; i++)
	{
		printf(" %d",arr[i]);
	}
	printf("\n");
}
