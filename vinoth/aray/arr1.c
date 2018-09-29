#include <stdio.h>
main()
{
	int a[6] = {2, 3, 4, 2, 3, 4};
	int i, j, n=6;
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<=n-1; j++)
		{
			if (a[i] == a[j])
			{
				a[j] = 0;
			}
		}
	}
	for (i=0; i<n; i++)
	{
		printf ("%d ", a[i]);
	}
}
