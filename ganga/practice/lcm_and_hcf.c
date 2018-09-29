#include <stdio.h>

void main()
{
	int x = 4, y = 5, a, b;
	a = x;
	b = y;

	while(a != b)
	{
		if(a < b)
		{
			a = a + x;
		}

		else
		{
			b = b + y;
		}
	}

	printf("lcm of %d and %d is %d\n", x, y, b);
	a = x;
	b = y;	

	while(a != b)
	{
		if(a > b)
		{
			a = a - b;
		}

		else
		{
			b = b - a;
		}
	}

	printf("hcf of %d and %d is %d\n", x, y, b);
}
