#include <stdio.h>

main()
{
	int n = 153, a = 0, b = 0;
	
	while(n > 0)
	{
		a = n % 10;
		n = n / 10;
		b = b + a * a * a;
	}
	printf("%d\n", b);
}
