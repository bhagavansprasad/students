#include <stdio.h>

main()
{
	int a[][4] = {
		5, 7, 5, 9,
		4, 6, 3, 1,
		2, 9, 0, 6
	};
	int *p;
	int (*q)[4];

	p = (int*) a;
	q = a;

	printf("%u %u\n", p, q);
	p++;
	q++;

	printf("%u %u\n", p, q);
}
