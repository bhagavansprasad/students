#include <stdio.h>
main()
{
	unsigned int a=0x12345678;
	char *p=(char *)&a;
	printf("%x\n",*p);
	if(*p==0x78)
		printf("little endian\n");
	else
		printf("big endian\n");
}
