#include<stdio.h>
main()
{
	int a = 0x12131415, i;
	char *p;
	p = &a;
	*p = 0;
	for(i = 0; i<4; i++)
	{
		p = ((char*)&a)+i;
		printf("%x\t",*p);
	}
	printf("%x\n",a);
}
