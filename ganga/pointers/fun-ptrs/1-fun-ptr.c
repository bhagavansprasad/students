#include "stdio.h"

int add(int x, int y)
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

	sum = add(a, b);
	printf("%d + %d = %d\n", a, b, sum);
}
