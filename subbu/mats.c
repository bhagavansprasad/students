#include<stdio.h>
main()
{
	int a[2][2]={{7,8},
	        	{9,10}},
		b[2][2]={{4,2},
			     {3,1}},
			c[2][2];
			int i,j,sum=0;
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					sum=sum+a[i][j]-b[i][j];
					c[i][j]=sum;
					printf("%d\t",c[i][j]);
					sum=0;
				}
				printf("\n");
			}
}			
