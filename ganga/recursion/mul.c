#include <stdio.h>

main()
{
	int m = mul(5, 20);
	printf("%d\n", m);
}
int mul( int a, int b)
{
	if( a == 0 || b == 0 )
		return 0;
	if( a == 1 && b == 1 )
		return 1;
	else
		return a + mul(a, b-1);
}
