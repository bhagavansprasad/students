#include<stdio.h>
main()
{
	int i,j,n=5,x=5,k;
	for(i=1;i<=n;i++)
	{
		for(k=1;k<x;k++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		x--;
		printf("\n");
	}
}
