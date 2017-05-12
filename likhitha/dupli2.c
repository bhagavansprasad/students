#include "stdio.h"

main()
{
	int i = 25;

	for (i = 2; i <= 100; i++)
	{
		if (is_prime(i) != 0)
			printf ("%d ", i);
		//printf ("-->%d is NOT prime\n", i);
	}
	printf ("\n");
}
