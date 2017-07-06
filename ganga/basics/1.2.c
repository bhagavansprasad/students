#include <stdio.h>

main()
{
	int n = 426, a = 0;
	while(n > 0)
	{
		a = (a * 10) + (n % 10);
		n = n/10;
	}
	printf("%d\n", a);
}
