#include <stdio.h>

main()
{
	static int a[] = {0, 1, 2, 3, 4};
	static int *p[] = {a, a+1, a +2, a+3, a+4};

	printf(" adresses of array a :%u %u %u %u \n", a, a + 1, a + 2, a +3);
	printf(" adresses of array p :%u %u %u %u \n", p + 0, p + 1, p + 2, p + 3);
	printf("%u %u %d \n", p, *p, *(*p));
}
