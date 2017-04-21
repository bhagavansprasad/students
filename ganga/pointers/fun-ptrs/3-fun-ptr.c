#include "stdio.h"

int addition(int x, int y)
{
	int c = 0;

	printf("x :%d\n", x);
	printf("y :%d\n", y);

	c = x + y;

	return c;
}

struct fun_data
{
	int (*fp)(int, int);
};

main()
{
	int a = 10;
	int b = 20;
	int sum = 0;
	struct fun_data fdata;

	fdata.fp = addition;

	sum = fdata.fp(a, b);

	printf("%d + %d = %d\n", a, b, sum);
}
