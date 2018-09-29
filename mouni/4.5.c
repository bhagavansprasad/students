#include <stdio.h>

main()
{
	int i,j,k, n = 2;
	int a[2][2]={{9,7},
				{5,2}
				};
	int b[2][2]={{10,8},
	{13,17}
	};
	int c[2][2]={0};
	
	for(i=0;i<n;i++)
	{
		for(j=0;j=n;j++)
		{
			for(k=0;k<n;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}

	for( i = 0; i < n; i++)
	{
		for( j = 0; j < n; j++)
		{
			printf("%5d", c[i][j]);
		}
		printf("\n");
	}
}
