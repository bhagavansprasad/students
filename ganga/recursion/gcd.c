#include <stdio.h>

main()
{
	int g = gcd(12,20);
	printf("%d\n", g);
}

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	if(a == 0)
		return a;
	if(a == b)
		return a;
	else
		return gcd(b, a % b);
}
