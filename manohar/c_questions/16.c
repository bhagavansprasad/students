#include <stdio.h>
int main()
{
	int a=5,b=15;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d\n",a,b);
}
