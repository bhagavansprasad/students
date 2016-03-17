#include <stdio.h>
main()
{
	int a[8] = {2,3,4,3,4,5,4,2};
	int i, j, k, n=8;
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[j] == a[i])
			{
				for(k=j; k<n; k++)
				
					a[k] = a[k+1];
				}
				n--;
			}
		}
	}

	for(i=0; i<n; i++)
	{
		printf ("%d ", a[i]);
	}
}
