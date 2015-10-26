#include<stdio.h>
main()
{
	int a=0x12131415;
	char* pa;
	pa=(char*)&a;
	printf("%x\t",*(pa+0));
	printf("%x\t",*(pa+1));
	printf("%x\t",*(pa+2));
	printf("%x\t",*(pa+3));
}
