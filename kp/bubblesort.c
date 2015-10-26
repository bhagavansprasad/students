#include <stdio.h>
main()
{
	int arr[]={6,5,8,9,4};
	int i,j,s;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				s=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=s;
			}
		}
	}
	printf("%d %d %d %d %d \n ", arr[0],arr[1],arr[2],arr[3],arr[4]);
}

