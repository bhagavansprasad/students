#include <stdio.h>
main()
{
	int a[][3] = {{1,2,3},
		{4,5,6},
		{7,8,9}};
	int b[][3] =  {{7,8,9},
		{4,5,6},
		{1,2,3}};

	int i=0,j=0,n=2;
	printf("printing array a[][] elements \n");

	for(i=0; i<=n; i++)
	{
		for(j=0; j<=n; j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}

	printf("printing array b[][] elements\n ");

	for(i=0; i<=n; i++)
	{
		for(j=0; j<=n; j++)
		{
			printf("%5d",b[i][j]);
		}
		printf("\n");
	}
}
