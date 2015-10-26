#include <stdio.h>
main()
{
	int a[3][3]={{1,2,3},
		{8,7,6},
		{1,9,4}
	};
	int b[3][3]={{1,2,3},
		{5,8,1},
			{6,4,9}
	};
	int c[3][3]={0},n=2,i=0,j=0,k=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			c[i][j]=0;
	}
	for(k=0;k<=n;k++)
	{
		c[i][j]+=a[j][k]*b[k][j];
		printf("%5d",c[i][j]);
	}
	printf("\n");
	for(k=0;k<=n;k++)
	{	
		printf("%5d",c[i][j]);
	}
	printf("\n");
}




		
