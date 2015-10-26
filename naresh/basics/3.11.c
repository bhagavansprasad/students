#include<stdio.h>
main()
{
	int i=0,j=0,k=0,n=5;
	for(i=1;i<=n;i++)
	{
			for(k=1;k<i;k++)
		{
			printf(" ");
		}
			for(j=1;j<=n-i+1;j++)
		{
			printf("%d",j);

		}

		printf("\n");
	}
}
