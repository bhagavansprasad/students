#include<stdio.h>
int linearsearch(int *,int,int);
main()
{
	int arr[]={1,3,8,2,6,9};
	int t,item=6,n=6;
    t=linearsearch(arr,item,n);
	if(t==-1)
		printf("element not found\n");
	else 
		printf("element found at: %d\n",item);
}
int linearsearch(int arr[],int item,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
	 if(item==arr[i])
		return i;
	}
		return -1;
}
