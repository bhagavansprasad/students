/* 1 2 3 4 5 4 3 2 1 */

#include <stdio.h>
int main()
{
	int n = 5, i = 0;
	for(i = 1; i <= n; i++)
	{
		printf(" %d",i);
	}
	for(i = n-1; i > 0; i--)
	{
		printf(" %d",i);
	}
	printf("\n");
}
