#include<stdio.h>
main()
{
	int i, j, k, n=6;
	for (i=1; i<=5; i++)
	{
		for (j=1; j<=n-i; j++)
		{
			printf ("%d", j);
		}
		printf (" ");
		for (k=j-1; k>0; k--)
		{
			printf ("%d", k);
		}
		printf ("\n");
	}
}

