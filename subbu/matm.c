#include<stdio.h>
main()
{
	int a[2][2]={{1,2},
		        {3,4}},
		b[2][2]={{5,6},
			    {7,8}},
	    c[2][2];
	int i,j,sum=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			sum=sum+a[i][j]+b[i][j];
			c[i][j]=sum;
			printf("%d\t",c[i][j]);
			sum=0;
		}
		printf("\n");
	}
}
