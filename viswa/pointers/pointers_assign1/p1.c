#include <stdio.h>
main()
{
	unsigned int a = 0x12131415;
	int i;
	char *c;

	c=(char*)&a;

	for(i = 3; i >= 0; i--)
	{
		printf("%p -- %5x\n", c+i, *(c+i));
	}
}
