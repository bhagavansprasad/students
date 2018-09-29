#include <stdio.h>
int fun(int a)
{
	int c;
	c=a>20?10:20;
	printf("%d\n",c);
	return c;
}
int main()
{
	int fun(int);
	int b;
	b = fun(40);
	printf("%d\n", b);
	return 0;
}
