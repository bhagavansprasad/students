#include<stdio.h>  
main()
{
	int i,j,n,temp;
	int arr[]={10,1,3,12,20,4,6,7,3,6,85,4,78,55};
         n=sizeof(arr)/sizeof(int);
         
        for(i=0;i<n;i++)
        printf("%d ",arr[i]);
        printf("\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
}
