#include<stdio.h>
main()
{
	int a=0X12131415;
		char ch1=*((char*)&a);
		char ch2=*((char*)&a+1);
		char ch3=*((char*)&a+2);
		char ch4=*((char*)&a+3);
		printf("%x\n",ch1);
		printf("%x\n",ch2);
		printf("%x\n",ch3);
		printf("%x\n",ch4);

}
