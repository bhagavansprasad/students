#include <stdio.h>
main()
{
	int a[5] = {2,4,1,6,7};
	int i, j, c, n=5;
	for (i=0; i<=n-1; i++)
	{
		for (j=0; j<=n-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				c = a[j];
				a[j] = a[j+1];
				a[j+1] = c;
			}
		}
	}
	for (i=0; i<n; i++)
	{
		printf ("%d ", a[i]);
	}
}
