#include<stdio.h>
int binarysearch(int arr[],int,int);
main()
{
	int arr[11]={1,5,2,6,3,7,4,8,9,2222,11};
	int item=2222,i,n=11,t;
	t=binarysearch(arr,item,n);
	if(t==-1)
		printf("element not found:%d\n",item);
	else 
		printf("element found:%d\n",item);
}
int binarysearch(int arr[],int item,int n)
{
	int mid,low=0,up=n-1;
	while(low<=up)
	{
		mid=(low+up)/2;
		if(arr[mid]>item)
			up=mid-1;
		else if(arr[mid]<item)
			low=mid+1;
		else
			return mid;
	}
	return -1;
}
