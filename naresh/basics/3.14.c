#include<stdio.h>
main()
{
	int n=5,i=0,j=0,k=0,l=0;
	for(i=1;i<=n;i++)
	{
		printf("%d",i);
	}
	for(j=4;j>=1;j--)
	{
		printf("%d",j);
	}
	printf("\n");
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf("%d",j);
		}
		for(k=1;k<=2*i-1;k++)
		{
			printf(" ");
		}
		for(k=n-i;k>=1;k--)
		{
			printf("%d",k);
		}

		printf("\n");
	}
}
