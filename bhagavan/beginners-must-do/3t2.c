#include "stdio.h"

main()
{
	int i = 0, j = 0;
	int n = 5;
	int x = 0; 

	for (i = 1; i <= n; i++)
	{
		for (j = n; j > x; j--)
			printf("%d", j);

		printf("\n");
		x++;
	}
}
