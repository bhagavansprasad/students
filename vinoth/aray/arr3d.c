#include <stdio.h>
#include <stdlib.h>
main()
{

	int a[3][3] = {
		{1,2,4},
		{4,5,6},
		{7,8,9}
	};
	int b[3][3] = {
		{9,8,7},
		{6,5,4},
		{3,2,1}
	};
	int c[3][3] = {0};
	int s[3][3] = {0};
	int i, j, k = 0;
	for (i=0; i<=2; i++)
	{
		for (j=0; j<=2; j++)
		{
			for (k=0; k<=2; k++)
			{
				c[i][j]=a[i][k]*b[k][j];
				s[i][j] = s[i][j]+c[i][j];
			}
		}
	}
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%5d",s[i][j]);
		}
		printf("\n");
	}
}
