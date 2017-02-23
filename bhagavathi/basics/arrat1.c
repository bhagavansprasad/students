#include<stdio.h>
main()
{
	int arr[5]={12,21,13,56,10};
	int i, j, n=5,k;
	for(i=0;i<=n-1;i++) 
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i] <= arr[j])
			{
			for(k=j;k<=n;k++)
			{
				//printf("%d\n",arr[i]);
			//}
			else
			{
				arr[j]=arr[j+1];
			}
		}
				printf("%d\n",arr[i]);
			}
	}
}	
