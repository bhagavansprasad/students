#include <stdio.h>
int main()
{
	int a[2][2]={{1 ,2},{0 ,1}};
	int b[2][3]={{1,1 ,2},{2,1,1}};
	int c[3][3] ,m=2 ,n=2 , p=2, q=3, i,j,k,sum=0;
	if(n==p)
	{
		for(i=0 ; i<m ; i++)
		{
			for(j=0 ; j<q ;j++)
			{
				for(k=0 ;k<n ;k++)
				{
					sum=sum+(a[i][k]*b[k][j]);
				}
				c[i][j]=sum;

				printf("\t%d",c[i][j]);
				sum=0;
			}
			printf("\n");
		}
	}
	else
		printf("matrix multiplication is not possible \n");
}
