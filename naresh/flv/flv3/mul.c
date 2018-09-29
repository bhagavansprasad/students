#include "stdio.h"

int product(int, int);

int main()
{
	int a = 3, b = 4, result;

	result = product(a, b);

	printf("Product of %d and %d is %d\n", a, b, result);

	return 0;
}
int product(int a, int b)
{
	if (a < b)
	{
		return product(b, a);
	}
	else if (b != 0)
	{
		return (a + product(a, b - 1));
	}
	else
	{
		return 0;
	}
}
