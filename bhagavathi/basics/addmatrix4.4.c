#include<stdio.h>
main()
{
	int a[2][2]={
		{1,2},
		{2,3}
	};

	int b[2][2] = {
		{3,4},
		{4,5}
	};
	int c[2][2];

	int i,j,k=0,n=2;
	int row = 2;
	int col = 2;

	printf("Array a....\n");
	for(i=0; i < row; i++)
	{
		for(j = 0; j < col;j++)
		{
			printf("%d ", a[i][j]);
		}
			printf ("\n");
		}
	printf ("\n");
	printf("Array b....\n");
	for(i=0; i < row; i++)
	{
		for(j = 0; j < col;j++)
		{
			printf("%d ", b[i][j]);
		}
		printf ("\n");
	}

	for(i=0; i < row; i++)
	{
		for(j = 0; j < col;j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
		printf ("\n");
	}


	printf ("\n");
	printf("Array a + b....\n");
	for(i=0; i < row; i++)
	{
		for(j = 0; j < col;j++)
		{
			printf("%d ", c[i][j]);
		}
		printf ("\n");
	}
	printf("\n");
}



