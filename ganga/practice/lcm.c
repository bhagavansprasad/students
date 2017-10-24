#include <stdio.h>
main()
{
	int x = 10, y = 12, i = 2, j;
	int p = x, q = y;
	int result, lcm = 1;

	if( x < y)
		result = x;
	else
		result = y;
	
	for(j = 0; i < result; j++)
	{
		if( (x % i) == 0 && (y % i) == 0)
		{
			x = x / i;
			y = y / i;
			lcm = lcm * i;
		}
		else
			i = i + 1;
	}
	lcm = lcm * x * y;
	printf("-->the lcm of %d and %d is %d\n", p, q, lcm);
}

#if 0
main()
{
	int x = 24, y = 36, a, b;
	a = x;
	b = y;

	while(a != b)
	{
		if(a < b)
			a = a + x;
		else
			b = b + y;
	}

	printf("lcm of %d and %d is %d",x,y,b);
}
#endif
