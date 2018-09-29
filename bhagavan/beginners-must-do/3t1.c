#include "stdio.h"

main()
{
	int i = 0, j = 0;
	int n = 5;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%d", j);
			printf("\n");
	}
}
