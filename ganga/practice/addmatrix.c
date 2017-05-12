#include <stdio.h>

void main()
{
	int a[2][2]={2,3,4,5};
	int b[2][2]={6,7,8,9};
	int c[2][2]={0};
	int row=2,col=2,i,j;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			c[i][j]=a[i][j]+b[i][j];

			printf("%5d\t",c[i][j]);
		}
		printf("\n");
	}	
}
