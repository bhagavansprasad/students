#include<stdio.h>
main()
{
	int a=0x12131415;
	printf("%x\n",a);
	 int t=(*(char*)&a);
	*((char*)&a)=*((char*)&a+3);
	*((char*)&a+3)=t;
	int b=*((char*)&a+1);
	*((char*)&a+1)=*((char*)&a+2);
	*((char*)&a+2)=b;
	printf("%x\n",a);

}
