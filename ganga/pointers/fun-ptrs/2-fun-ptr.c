#include "stdio.h"

int addition(int x, int y)
{
	int c = 0;

	printf("x :%d\n", x);
	printf("y :%d\n", y);

	c = x + y;

	return c;
}

main()
{
	int a = 10;
	int b = 20;
	int sum = 0;
	int (*fp)(int, int);

	fp = addition;

	sum = fp(a, b);
	printf("%d + %d = %d\n", a, b, sum);
}
