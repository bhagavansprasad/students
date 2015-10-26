#include<stdio.h>
main()
{
	int i,j,n=2;
	int a[2][2]={{1,2},{3,4}};
	int b[2][2]={{5,6},{7,8}};
	int c[2][2];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
