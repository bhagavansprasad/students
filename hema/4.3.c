#include<stdio.h>
main()
{
	int i,j,temp;
	int arr[5]={5,8,1,3,9};
	for(i=0;i<=4;i++)
	{
		for(j=i+1;j<=4;j++)
		{
			if(arr[i]>arr[j])
			{
			
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;

			}
		}
	}
	for(i=0;i<=4;i++)
	printf("numbers are %d\n",arr[i]);
}
