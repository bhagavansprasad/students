#include <stdio.h>
main()
{
	unsigned int a=0x15141312;
	int i;
	char *c;
	c=(char*)&a;
	for(i=0;i<=3;i++)
	{
			printf("%x",*(c+i));
	}
}
