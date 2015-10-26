#include<stdio.h>
main()
{
int a[3][3]={
				{4,1,8},
				{1,5,9},
				{3,1,7},
			    	};
int b[3][3]={
              {2,5,2},
			  {2,2,6},
			  {5,2,4},
			    };
int c[3][3],i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<=2;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf("the resultant matrix is:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%5d",c[i][j]);
		}
		printf("\n");
	}
	return(0);
}

