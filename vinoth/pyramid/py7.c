#include<stdio.h>
int main()
{
	int i, j, k, l, n=5;
	for (i = 1; i <= n; i++)
		printf (" %d", i);
	for (i = n-1; i > 0; i--)
		printf (" %d", i);
	printf ("\n");
	for (i = 1; i <= n-1; i++)
	{
		for (j = 1; j <= n-i; j++)
			printf (" %d", j);
		for (k = 1; k <= n-j+i; k++)
			printf ("  ");
		for (l = j-1; l > 0; l--)
			printf (" %d", l);
			printf ("\n");
	}
}

