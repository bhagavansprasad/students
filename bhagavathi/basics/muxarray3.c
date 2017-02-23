#include <stdio.h>
main()
{
	int a[3][3]={
		{1,2,2},
		{2,3,1},
		{2,3,1}
	};
	int b[3][3]={
		{3,4,2},
		{4,5,1},
		{2,1,3,}
	};
	int c[3][3];
	int i,j,k,sum,n=3;

	/*a array*/
	printf("array of a...\n");
	for( i=0; i<n; i++ )
	{
		for( j=0; j<n; j++ )
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	/*i array*/
	printf("array of b...\n");
	for( i=0; i<n; i++ )
	{
		for( j=0; j<n; j++ )
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	
	/* core calculation of multipication*/
	for( i=0; i<n; i++ )
	{	
		for( j=0; j<n; j++ )
		{
		sum=0;
			for( k=0; k<n; k++ )
			{
				sum= sum + a[i][k] * b[k][j];
			}
			c[i][j]=sum;
//			printf("\n");
		}
	}

	/*answer of the array*/
	printf("mux of c=a*b...\n");
	for( i=0; i<n; i++ )
	{
		for( j=0; j<n; j++ )
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
