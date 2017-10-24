#include<stdio.h>
void main()
{
	int i,j;

	int a[3][3] = { 
		{3,2,1},
		{2,3,2},
		{1,3,4}
	};

	int b[3][3] = { 
		{5,6,2},
		{9,8,7},
		{7,0,6}
	};

	int c[3][3] = {0};

	printf("values of array 'a'.....\n");
	for(i=0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("values of array 'b'.....\n");
	for(i=0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%5d", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}

	printf("After adding 'a' + 'b', values of array 'c'.....\n");
	for(i=0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%5d", c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
