#include <stdio.h>
main()
{
	int a[5] = {5,4,3,2,1};
	int i, j, n=5, c;
	for (i=0; i<=n-1; i++)
	{
		for (j=i+1; j<=n-1; j++)
		{
			if (a[i] < a[j])
			{
				c = a[i];
				a[i] = a[j];
				a[j]  = c;
			}
		}
	}
	for (i=0; i<n; i++)
	{
		printf ("%d ", a[i]);
	}
}

