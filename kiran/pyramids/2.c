/* 1 2 3 4 5
   1 2 3 4
   1 2 3
   1 2
   1*/
#include <stdio.h>
int main()
{
	int n = 5, i = 0, j =0;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n-i+1; j++)
		{
			printf(" %d",j);
		}
		printf("\n");
	}
}
