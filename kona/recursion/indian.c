#include <stdio.h>
main()
{
	int a=0x12131415;
	char *p;
	p=(char *)&a;
	if(p[0]==0x15)
	printf("little\n");
	else
	printf("big");

}
