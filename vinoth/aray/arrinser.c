#include <stdio.h>
main()
{
	int a[5] = {2,4,5,7,3};
	int i, j, c, n=5;
	for (i=0; i<n; i++)
	{
		c = a[i];
		for (j=i-1; j>=0 && c<a[j]; j--)
		{
			a[j+1] = a[j];
		}
			a[j+1] = c;
	}
	for (i=0; i<n; i++)
	{
		printf ("%d \n", a[i]);
	}
}
