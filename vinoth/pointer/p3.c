#include <stdio.h>
main()
{
	int a = 0x12131415;
	int i;
	char *p, ch1=0, ch2=0, ch3=0, ch4=0;
	p = &a;
	for (i=3; i>=0; i--)
	{
		printf ("ch%d contains %x, ch%d=%x \n", 4-i, *(p+i), 4-i, *(p+i));
	}
}
