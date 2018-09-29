#include<stdio.h>
main()
{
	int i,j,n=5,x=5,k;
	for(i=1;i<=n;i++)
	{
		for(k=i;k>1;k--)
		{
			printf(" ");
		}
		for(j=1;j<=x;j++)
		{
			printf("%d",j);
		}
		x--;
		printf("\n");
	}
}

