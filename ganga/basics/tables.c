#include <stdio.h>

main()
{
	int i, n = 7, result = 0;
	for(i = 1; i <= 10; i++)
	{
		result = n * i;
		printf("%d * %d = %d \n", n, i, result);
	}
}
