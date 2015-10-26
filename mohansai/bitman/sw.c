#include "stdio.h"

void show_bits(int n)
{
	int mask,i,k;

	printf("-->:%3d -->", n);

	for(i=31 ; i >= 0; i--)
	{
		mask = 1 << i;
		k = n & mask;
		if(k== 0)
			printf("0 ");
		else
			printf("1 ");
	}
	printf("\r\n");
}


main()
{
	int a = 10;

	show_bits(a);
	a = a >>1 ;
	show_bits(a);
	a = a >>1 ;
	show_bits(a);

	a = 10;
	show_bits(a);
	a = a << 1 ;
	show_bits(a);
	a = a << 1 ;
	show_bits(a);

	a = -10;
	show_bits(a);
	a = a >>1 ;
	show_bits(a);
	a = a >>1 ;
	show_bits(a);

	a = -10;
	show_bits(a);
	a = a << 1 ;
	show_bits(a);
	a = a << 1 ;
	show_bits(a);
}

