#include<stdio.h>
main()
{
	int i,j,k,n=3;
	int a[4][4]={{1,2,3,6},{3,6,4,1},{9,5,7,5},{1,2,3,4}};
	int b[4][4]={{5,6,1,7},{2,7,8,2},{4,7,1,9},{2,7,1,9}};
	int c[4][4];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			c[i][j]=0;
			for(k=0;k<=n;k++)
			{
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
