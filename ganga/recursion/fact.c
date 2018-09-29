#include <stdio.h>

main()
{
	int f = fact(5);
	printf("%d\n", f);
}

int fact(int n)
{
	if(n == 0)
		return 1;
	else
		return( n * fact(n-1));
}
