#include <stdio.h>

main()
{
	int bin = 111, m = 1, dec = 0;
	while(bin > 0)
	{
		dec = dec + (bin % 2 * m);
		bin = bin / 10;
		m = m * 2;
	}
	printf("%d\n", dec);
}
