#include<stdio.h>
main()
{
	int arr[10]={1,2,1,2,3,4,5,4,5,6};
	int i,m,j=0,n=10,k,t;
	for(i=0;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(arr[i]==arr[j])
			{
				for(t=1;t<=n;t++)
				{
					arr[j]=arr[k];
				}
			}
			printf("element=%d\n",arr[i]);
		}
	}
}

