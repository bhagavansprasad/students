# include <stdio.h>
main ()
{
	int i,j,k,n = 2;
	for (i = 1;i <= n; i++)
	{
		printf("%d",i);
	}
	for (j = (2*n)-3 ;j < 2*n ;j-= 2)
	{
		printf(" ");
	}
	for (k = 1; k > n; k--)
	{
		printf("%d",k);
	}
	printf("\n");
}
