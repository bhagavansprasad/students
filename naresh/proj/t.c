#include "stdio.h"

int fun(int a);

int main()
{
	int a = 10, b = 0;

	printf("%d\n", a);
	//printf("%d\n", b);

	b = b + a;

	return 0;

	fun(a);
}

int fun(int a)
{
	printf("%d\n", a);

	return 0;
}
