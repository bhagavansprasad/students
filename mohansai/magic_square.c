#include "stdio.h"
#define ARRAY_SIZE 3 

int n = ARRAY_SIZE;
int a[ARRAY_SIZE][ARRAY_SIZE] = {{0}};

main()
{
	int r=0, c=n/2;
	int i;

	for(r=0;r < n; r++)
	{
		for(c = 0; c < n; c++)

			a[r][c]=0;
	}
	r=0;
	c=n/2;

	for(i = 1 ; i <=n*n ; ++i )
	{
        if (r < 0)
		{
			//TODO
		}

		if (c >= n)
		{
		}

		if (a[r][c] != 0)
		{
			//TODO
		}

		a[r][c] = i;
		r--;
		c++;
	}

#if 0
	for(i = 1 ; i <=n*n ; ++i )
	{
		if(a[r][c] != 0)
		{
			c--;
			r=r+2;

			a[r][c]=i;
			r--;	
			c++;
		}
		else
		{
			if(a[r][c]==0)
			{
				a[r][c]=i;
				r--;
				c++;

				if(r==-1)
				{
					r = n-1;
				}
				if(c == n)
				{
					c = 0;
				}
			}
		}
	}	
#endif
	printf("The Magic Square...\n");

	for( r=0 ; r < n; r++)
	{
		for(c = 0; c < n; c++)
			printf("%4d",a[r][c]);

		printf("\n");
	}
}
