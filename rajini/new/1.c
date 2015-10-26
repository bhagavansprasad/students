#include<stdio.h>
main()
{
	int i=0, j=0;
	int k=0;
	int n=8;
	for(i=1;i<=n;i++)
	{
		printf(" *");
	}
	for(k=1;k<=n-2;k++)
	{
		printf("\n");

		for(j=1;j<=n;j=j+3)
		{
			printf(" *");
			for(i=1;i<=n-2;i++)
			{  
				printf("  ");
			}
		}

	}
	printf("\n");

	for(k=1;k<=n;k++)
	{
		printf(" *");
	}
}

