#include <stdio.h>

main()
{
	int i = 20, j = 10, d;
	d = &i - &j;
	printf("%u %u %d\n", &i+1, &j, d);
}
