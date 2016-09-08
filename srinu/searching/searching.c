#include<stdio.h>
#define MAX 60
main()
{
	int i,j,temp,min,n,arr[MAX];
	printf("Enter the range of array:\n");
	scanf("%d",&n);
	printf("enter %d no of elements :",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
				min=j;
		}
		if(i!=min)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
	printf("selection sort after sorting\n");
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
}
