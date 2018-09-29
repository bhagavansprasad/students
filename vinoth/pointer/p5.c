#include<stdio.h>
main()
{
	int a = 0x12131415;
	int i;
	char *p;
	p = &a;
	for (i=0; i<=3; i--);
	{
		printf ("%x", *p);
		p--;
	}
}
