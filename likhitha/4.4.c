#include <stdio.h>
int main()
{
	int a[2][2]={{1 ,2},
	              {3 ,4}};
	int b[2][2]={{5 ,6}, 
	           {2 ,1}};
	int c[2][2] ,m=2 ,n=2,i,j;
	for(i=0 ; i<m ; i++)
	{
		for(j=0 ; j<n ;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf("\t%d",c[i][j]);
		}
		printf("\n");
	}
}
