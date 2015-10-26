#include<stdio.h>
#define MAX 60
int binarysearch(int *,int,int);
main()
{
	int arr[MAX], item,i,n,index;
	printf("Enter the range of an array:");
	scanf("%d",&n);
	printf("enter %d no of elements for an array:",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter an element to search:");
	scanf("%d",&item);
	index=binarysearch(arr,item,n);
	if(index==-1)
		printf("element not found\n");
	else 
		printf("element found at %d position\n",index);
}
int binarysearch(int arr[],int item,int n)
{
	int mid,low=0,up=n-1;
	while(low<=up)
	{
		mid=low+up/2;
		if(arr[mid]>item)
			up=mid-1;
		else if(arr[mid]<item)
			low=mid+1;
		else
			return mid;
	}
	return -1;

}
