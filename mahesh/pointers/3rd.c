#include<stdio.h>
main()
{
	int a=0x12131415;
	short sh1=*((short*)&a);
	short sh2=*((short*)&a+1);
	printf("%x\n",sh1);
	printf("%x\n",sh2);



}
