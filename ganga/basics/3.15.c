#include<stdio.h>

void main()
{
	int i, j, k, n = 5;
	
	for(i = n; i >= 1; i--)
	{
		for(j = 1; j <= n; j++) 
		{ 
			if(j <= i)
				printf("%d", j);
			else
				printf(" ");
		}

		for(k = n-1 ; k >= 1; k--)
		{ 
			if(k <= i)
				printf("%d", k);
			else
				printf(" ");
		}

		printf("\n");
	}
}
