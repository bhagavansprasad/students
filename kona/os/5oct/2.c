#include <stdio.h>
main()
{
	int *p=NULL;
	p=0x7fff5d862448;
	*p=20;
	printf("---the value at p is %d\n",*p);
}
