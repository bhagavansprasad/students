#include <stdio.h>
main()
{
	int i,j,k,n=5;
	for (i=1; i<=n; i++)
	{
		for (j=i-1; j>0; j--)
		{
			printf(" ");
		}
		for (k=1; k<=n-i+1; k++)
		{
			printf("%d",k);
		}
		printf("\n");
	}
}

