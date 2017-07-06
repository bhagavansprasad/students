#include<stdio.h>
main()
{
	int temp,i,j,arr[5]={1,29,43,3,4};
	printf("before sorting ");

	for(i=0;i<5;i++)
	printf(" %d ",arr[i]);

	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			if(arr[j] < arr[j+1])
			{
				temp=arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;

			}
		}
	}
	printf("\nafter bubble sorting ");
	for(i=0;i<5;i++)
		printf(" %d ",arr[i]);
}
