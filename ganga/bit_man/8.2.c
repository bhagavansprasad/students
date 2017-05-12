#include <stdio.h>

main()
{
	int n = 4;
	n = n & (n - 1);
	if(n == 0)
		printf(" n is power of two\n");

	else
		printf(" n is not a power of two\n");
}
