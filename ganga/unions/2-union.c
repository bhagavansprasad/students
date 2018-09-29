#include <stdio.h>

main()
{
	union u
	{
		short int a;
		short int b;
	}u1;
	u1.a = 65535;
	u1.b = 255;
	printf("-->a : %d\n", u1.a);
	printf("-->b : %d\n", u1.b);
}
