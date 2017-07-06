#include <stdio.h>
main()
{
	int a = 234, c = 0;
	while( a > 0)
	{
		c = ( c * 10) + (a %10);
		a = a/10;
	}
	printf("%d\n", c);
}
