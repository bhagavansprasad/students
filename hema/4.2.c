#include<stdio.h>
main()
{
	int i,j,n=8,k;
	int arr[8]={5,6,8,2,5,7,8,6};
	for(i=0;i<=7;i++)
	{
		for(j=i+1;j<7;j++)
		{	
			if(arr[i]==arr[j])
			{		
				for(k=j;k < n;k++)
				arr[k]=arr[k+1];n--;
			}
		}
	}
	for(k=0;k<n;k++)
	{
		printf("elements are %3d\n",arr[k]);
	}
}
