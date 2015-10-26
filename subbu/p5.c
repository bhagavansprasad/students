#include<stdio.h>
main()
{
	int a=0x12131415;
	printf("%x\n",a);

	char* pa;
	pa=(char*)&a;
	int temp1;
	temp1=*((short*)&a);
	*((short*)&a)=*((short*)&a+1);
	*((short*)&a+1)=temp1;
	printf("%x\n",a);
}	

