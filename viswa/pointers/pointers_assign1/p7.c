#include <stdio.h>
main()
{
	unsigned int a=0x15141312;
	int i,k=0;
	short int *c;
	c=(short int*)&a;
	for(i=0;i<=1;i++)
	{
			printf("%x",*(c+i));
	}
}
