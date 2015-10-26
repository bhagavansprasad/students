#include <stdio.h>
int main()
{
	int i =0, j =0, k = 0, n = 5;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			printf(" %d",j);
		}
		for(k = j-2; k > 0; k--)
		{
			printf(" %d",k);
		}
		printf("\n");
	}
}
