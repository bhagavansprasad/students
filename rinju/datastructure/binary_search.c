#include<stdio.h>
main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int min=0,max=(sizeof(arr)/sizeof(arr[0]));
	int mid,n,i,flag=0;
//	mid=(max+min)/2;
	printf("enter the element to search");
	scanf("%d",&n);

	for(i=0;i<10;i++)
	{
		mid=(max+min)/2;
		if(arr[mid] == n)
			{
			flag =1;
			printf("search element is %d\n",arr[mid]);
			break;
			}
		else if(n < arr[mid])
		{
			max=mid;
			//mid=(min+max)/2;
		}
		else if(n > arr[mid])
		{
		min = mid;
		//mid= (min+max)/2;
		}
	}
	if(flag==1)
		printf("found");
	else 
		printf("not found");
}
