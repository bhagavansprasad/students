/* 1 2 3 4 5
   2 3 4 5
   3 4 5
   4 5
   5*/
#include <stdio.h>
int main()
{
	int n = 5, i = 0, j = 0;
	for(i = 1; i <= n; i++)
	{
		for(j = i; j <= n; j++)
		{
			printf(" %d",j);
		}
		printf("\n");
	}
}
