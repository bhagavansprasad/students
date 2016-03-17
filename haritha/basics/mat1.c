#include<stdio.h>
main()
{
	int i,j,a[2][2]={
		{1,2},{3,4}
	};

	int b[2][2]={
		{4,5},{6,7}
	};
	int c[2][2];
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{

			printf("%d\t",c[i][j]);


		}
		printf("\n");

	}


}
