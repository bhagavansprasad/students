# include <stdio.h>
main ()
{
	int i,j,k,n = 2;
	int a[2][2] = { {1 , 4} , {2 , 3} };
	int b[2][2] = { {1 , 4} , {2 , 3} };
	int c[2][2];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4d",b[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < 2; k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
		printf("%4d",c[i][j]);
		}
		printf("\n");
	}
}
