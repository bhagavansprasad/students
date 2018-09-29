#include<stdio.h>
main()
{
	int a=0x12131415;
	printf("%x\t",*((short*)&a+1));
	printf("%x\t",*((short*)&a));
}
