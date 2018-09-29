#include <stdio.h>
main()
{
	int a= 0x12131415;
	int i;
	short int *p;
	p = &a;
	for (i=1; i>=0; i--)
	{
		printf ("%d\t", p);
		printf ("%u\t %x \n", *(p+i), *(p+i));
	}
}
