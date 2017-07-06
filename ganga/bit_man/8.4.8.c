#include <stdio.h>

main()
{
	int num = 0, x = 10, y = 12;
	num = bitAnd(x, y);
	printf("bitweise and of x and y is :%d\n", num);
}

int bitAnd(int a, int b)
{
	int c;
	c = ~a | ~b;
	c = ~c;
	return c;
}
