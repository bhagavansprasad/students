#include <stdio.h>
main()
{
	int i=0,j=0;
	int a[3][3]={ {1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int b[3][3]={ {5,8,2},
		{7,4,1},
		{9,3,6}
	};
	int c[3][3]={0};
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
	printf("%5d",c[i][j]);
	}
	
	printf("\n");
	}
}

