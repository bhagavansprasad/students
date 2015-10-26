#include<stdio.h>
main()
{
	int a=0X12131415;
		printf("%x\n",a);
		printf("%x\t",*((char*)&a));	
		printf("%x\t",*((char*)&a+1));
		printf("%x\t",*((char*)&a+2));
		printf("%x\n",*((char*)&a+3));
		printf("%x\t",*((short*)&a));
		printf("%x\n",*((short*)&a+1));


}
