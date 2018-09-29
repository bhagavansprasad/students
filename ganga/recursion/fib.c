#include <stdio.h>

main()
{
	int f = fib(5);
	for(f = 0; f <= 5; f++)
	{
		printf("%d\n", fib(f));
	}
}

int fib(int n)
{
	if(n == 0)
		return 0;
	else if( n == 1)
		return 1;
	else
		return (fib(n-1) + fib(n-2));
}
