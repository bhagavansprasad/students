#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i,j,k,r1=3,r2=3,c1=3,c2=3;;

	int a[3][3] = { 
		{3,2,1},
		{2,3,2},
		{1,3,4}
	};

	int b[3][3] = { 
		{9,8,7},
		{7,0,6},
		{1,3,4}
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

	if(r2 != c1)
	{
		printf("multiplication is not applicable because r2 :%d nad c1:%d are not same\n",  r2, c1);
		exit(1);
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}

	printf("After multiplying 'a' * 'b', values of array 'c'.....\n");
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


