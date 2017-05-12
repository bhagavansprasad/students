#include <stdio.h>

main()
{
	int sum = add(10,20);
	printf("%d\n", sum);
}

int add(int a, int b)
{
	if(a == 0 && b != 0)
		return b;
	if(b == 0 && a != 0)
		return a;
	else
		return a + b; 
}
