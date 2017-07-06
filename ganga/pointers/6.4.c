#include <stdio.h>

main()
{
	int t,s,a = 0x12131415;
	char *cp = &a;

	printf("-->before swap %x\n", a);

	t = *cp;
	*(cp) = *(cp+3);
	*(cp+3) = t;

	s = *(cp+1);
	*(cp+1) = *(cp+2);
	s = *(cp+2);

	printf("--> after swap %x\n", a);
}
