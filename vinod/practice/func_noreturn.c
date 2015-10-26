#include <stdio.h>
fun(int y)
{
	register int x=10;
	printf("This is fun, y : %d\n",y);
	return x;
}
int main()
{
	register int y=20;
	int x;
	printf("Main function\n");
	x = fun(y);
	printf("x : %d\n", x);
	return 0;
}
