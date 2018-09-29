#include <stdio.h>

main()
{
	int a = 1024;
	printf("%f\n", a);
	float *b, *c;
	b = &a;
	c = b;
	printf("%u %u %u\n", &a, b, c);
	printf("%d %d %d %d\n", a, *(&a), *b, *c);
}
