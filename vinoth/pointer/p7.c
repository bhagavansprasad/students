#include <stdio.h>
main()
{
	int a = 0x12131415;
	int i, j=0, t;
	short int *p;
	p = &a;
	for (i=1; i>j; i--,j++)
	{
		t = *(p+i);
		*(p+i) = *(p+j);
		*(p+j) = t;
	}
	for (i=1; i>=0; i--)
	{
		printf ("%x \n", *(p+i));
	}
}
