#include <stdio.h>
#include <stdlib.h>
#define NUM 5
insert_arr(int *arr,int num,int index)
  {
  
  (*arr)[index]=num;
  printf("%d ",(*arr)[index]);
  
  

  
  }
main()
{
	int i,n,j=0,index;
	int arr[NUM];
	printf("enter arr element:");
	for(i=0;i<NUM;i++)
	{
	scanf(" %d ",&arr[i]);
	}
		printf("enter index :");
		scanf(" %d ",&index);
	insert_arr(&arr,4,index);
		printf(" \nelement of arr:");
		
	for(i=0;i<NUM;i++)
	{
	printf(" %d ",arr[i]);
	}
	//printf("enter a  position to delete\n");
	/*
    scanf(" %d ",&n);
	for(i=n-1;i<NUM;i++)
	{
	arr[i] = arr[i+1];
	}
	
	for(i=0;i<NUM;i++)
	{
		printf(" %d ",arr[i]);
	}
*/
}
