#include<stdio.h>
#include<stdlib.h>

main()
{
	int a[3][3] = { 
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int b[3][3] = { 
		{7, 0, 4},
		{5, 2, 4},
		{3, 9, 8}
	};
	int c [3][3]= {0};
	int i,j;

	/*printf("Array a values are ...\n");
	for (i=0; i<=2; i++)
	{
		for (j=0; j<=2; j++)
		{
			printf ("%5d", a[i][j]);
		}
		printf("\n");
	}

	printf("Array b values are ...\n");
	for (i=0; i<=2; i++)
	{
		for (j=0; j<=2; j++)
		{
			printf ("%5d", b[i][j]);
		}
		printf("\n");
	}*/

	printf("Array c values are ...\n");
	for (i=0; i<=2; i++)
	{
		for (j=0; j<=2; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			printf ("%5d", c[i][j]);
		}
	printf("\n");
	}
	}
