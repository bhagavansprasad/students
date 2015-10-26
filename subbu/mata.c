#include<stdio.h>
main()
{
	int a[3][3]={{1,2,3},
		{3,4,5},
		{5,6,7}},
		b[3][3]={{7,8,9},
			{9,10,11},
			{11,12,13}},
		c[3][3];
	int i=0,j=0,sum=0,k;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
		 for(k=0;k<=2;k++)
		  {
				sum=sum+a[i][k]*b[k][j];
          }
			c[i][j]=sum;
			printf("%d\t",c[i][j]);
			sum=0;
		}	
		printf("\n");
	}
}	

