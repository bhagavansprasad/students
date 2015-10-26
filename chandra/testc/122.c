#include<stdio.h>

int main()
{
	int a;
	a = fun(20);
	printf("a is : %d\n", a);
	return 0;
}
int fun(int aa)
{
	int bb;
	bb = aa * aa;
	return bb;
}

