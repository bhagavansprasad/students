#include<stdio.h>
#define SIZE 10
main()
{
	int arr[SIZE],i,j,n,item,index;
	/*printf("enter no of elements do u want");
	scanf("%d",&n);*/
	printf("enter elements");
	for(i=0;i<SIZE-1;i++)
	{
		//printf("enter elements is %d",i+1);
		scanf("%d",&arr[i]);
	}
	printf("enter the item to be inseted\n");
	scanf("%d",&item);
	printf("enter the index\n");
	scanf("%d",&index);
	for(j=SIZE-2;j>=index;j--)
	{
		arr[j+1]=arr[j];
	}
	arr[j+1]=item;
	for(i=0;i<SIZE;i++)
	{
		printf("%d",arr[i]);
	printf("\n");
	}
}
