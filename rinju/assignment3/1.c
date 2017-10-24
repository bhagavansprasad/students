#include <stdio.h>
#include <string.h>
#define NUM 10
main()
{
	int i,n;
	int arr[NUM];
		printf("enter element for arr:");
	for(i=0;i<NUM;i++)
	{
		scanf(" %d ",&arr[i]);
	}
		printf(" element of arr:");
		
	for(i=0;i<NUM;i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("enter a  position to delete\n");
	
    scanf(" %d ",&n);
	for(i=n-1;i<NUM;i++)
	{
	arr[i] = arr[i+1];
	}
	
	for(i=0;i<NUM;i++)
	{
		printf(" %d ",arr[i]);
	}

}
