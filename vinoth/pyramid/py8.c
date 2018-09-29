#include <stdio.h>
main()
{
	int i, j, k, n=5;
	for (i=1; i<=5; i++)
	{
		for (j=1; j<=n-i; j++)
		{
			printf (" ");
		}
		for (k=5; k>=j; k--)
		{
			printf ("* ");
		}
		printf ("\n");
	}
}
