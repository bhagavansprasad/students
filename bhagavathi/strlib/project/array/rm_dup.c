#include <stdio.h>
main()
{
	int arr[]={2,1,1,1,3,3,3,4,5};

	int i,j,k,n=0;

	n = sizeof(arr)/sizeof(int);

	for(i=0;i< n;i++)
		printf("%d ",arr[i]);
	printf ("\n");


	for(i=0;i<n;i++)
	{
		for(j=i+1; j<n;j++)
		{
			if(arr[i] == arr[j])
			{
				for(k=j; k<n; k++)
				{
					arr[k]=arr[k+1];
				}
				n--;
				j--;
			}
		}
	}

	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf ("\n");
}
