/* * * * * * 
   *       *
   *       *
   *       *
   * * * * *  */

#include <stdio.h>
int main()
{
	int n = 10,i,j,k = 2;
	for(i = 1; i <= n; i++)
	{	
		printf(" *");
	}
	printf("\n");
	for(i = 1; i <= n-2; i++)
	{
		for(j = 1;j <= n;j+=n-1)
		{
			printf(" *");
			for(k = 2; k <= n-1; k++)
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	for(i = 1; i<= n; i++)
	{
		printf(" *");
	}
}
