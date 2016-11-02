#include<stdio.h>
{
	int i,j;
	int arr[8]={5,6,8,2,5,9,4,6};
	for(i=0;i<=7;i++)
	{
		for(j=i+1;j<=7;j++)
		{
			if(arr[i]==arr[j])
				arr[j]=0;
		}
		arr[j+1]=arr[j+2];
	}
	for(i=0;i<=7;i++)
	{
	printf("new elements are %d\n",arr[i]);
	}
}

