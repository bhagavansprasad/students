#include <stdio.h>
main()
{
	int a = 0x12131415;
	short *psh = &a;
	printf ("%d\n", psh);
	psh++;
	printf ("%d\n", psh);
}
