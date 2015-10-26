#include <stdio.h>
void sum(int, int);// bbby default it is extern
int main()
{
	int a = 5, b = 10;
	sum(a, b);
	return 0;
}

void sum(int a, int b)
{
	printf("%d", a+b);
}

// o/p: 15
