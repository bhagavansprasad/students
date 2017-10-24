#include<stdio.h>
main()
{
int arr[10]={1,6,2,8,4,3,7,9,12,16};
int temp,i,j;
	printf(" before sorting\n");

	for(i=0;i<10;i++)
	printf(" %d ",arr[i]);

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
		//if(arr[i] > arr[j])
		if(arr[i] < arr[j])
		{
			temp = arr[i];
			arr[i]= arr[j];
			arr[j] = temp;
		}
	}
}
	printf("\nafter sorting\n");

	for(i=0;i<10;i++)
	printf(" %d ",arr[i]);
}
