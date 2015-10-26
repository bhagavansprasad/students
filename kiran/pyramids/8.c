/* 1               1
   1 2           2 1
   1 2 3       3 2 1
   1 2 3 4   4 3 2 1
   1 2 3 4 5 4 3 2 1 */

#include <stdio.h>
int main()
{
	int n = 5, i,j,k,l;
	for(i = 1; i <= n-1; i++)
	{
		for(j = 1; j <= i; j++)
			printf(" %d",j);
		for(k = 1; k <= 2*n-j-i; k++)
			printf("  ");
		for(l = i; l > 0; l--)
			printf(" %d",l);
		printf("\n");
	}
	for(i = 1; i <= n; i++)
		printf(" %d",i);
	for(i = n-1; i > 0; i--)
		printf(" %d",i);
	printf("\n");
}
