#include<stdio.h>
int main()
{
	int i,j,k,n=2;
	int a[2][2]={{1,2},{2,1}};
	int b[2][2]={{1,2},{2,1}};
	int c[2][2];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]+=(a[i][k]*b[k][j]);
			}
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
}
