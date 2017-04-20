#include <stdio.h>

main()
{
	int c, i = 1;
	int f = fib(5);
	for(c = 1; c <= 5; c++)
	{
		printf("%d\n", fib(i));
		i++;
	}
}

int fib(int n)
{
	if(n == 0)
		return 0;
	if( n == 1)
		return 1;
	return (fib(n-1) + fib(n-2));
}
