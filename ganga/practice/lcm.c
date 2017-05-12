#include <stdio.h>

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
