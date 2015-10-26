#include <stdio.h>
main()
{
	int i,j,n=6,a[10]={3,10,9,6,5,1},t;
		for(i=0;i<n;i++)
		{
			for(j=0;j<(n-1)-i;j++)
			{
				if(a[j]>a[j+1])
				{

					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
	printf("%d\t",a[j]);
	for(i=0;i<n;i++)
	{
		printf("%4d\n",a[i]);
	}

}
