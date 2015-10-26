#include <stdio.h>
int main()
{
int arr[10] = {6,100,34,56,76,3,8,2,2,4};
int i = 0, j = 0, swap = 0, n = 10;
for(i = 0; i < n; i++)
{
	for(j = i+1; j < n; j++)
	{
		if(arr[i] < arr[j])  /* >for assending order, < for dessending order*/
		{
			swap = arr[i];
			arr[i] = arr[j];
			arr[j] = swap;
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
