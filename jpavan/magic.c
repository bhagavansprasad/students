#include<stdio.h>
#include <stdlib.h>
main()
{
	int i,j,n=5,k,a[n][n];
	i=n-1,j=(n-1)/2;

	for(k=1;k<=n*n;k++)
	{
		a[i][j]=k;
		i++;
		j--;

		if (k%n==0)
		{
			i = i-2;
			j++;
		}
		else if(i==n)
		{
			i=0;
		}
		else  if(j==-1)
		{
			j=n-1;
		}	
	}

	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}

}

