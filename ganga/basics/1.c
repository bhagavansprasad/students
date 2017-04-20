#include <stdio.h>

void main()
{
	int x, y = 2, b, a = 10;

	b = a++ + ++a;
	
	x = ++y;

	printf("%3d%3d%3d%3d%3d%3d\n", b, a++, a, ++a, x, y);
}
