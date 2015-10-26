# include <stdio.h>
main ()
{
	int i,j,k,n = 5;
	for (i = 0; i <= n; i++)
	{
		for (j = n; j > i; j--)
		{
			printf(" ");
		}
		for  (k = 1; k <= i; k++)
		{
			printf("%d",k);
		}
		printf("\n");
	}

}
