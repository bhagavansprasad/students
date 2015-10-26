#include <stdio.h>
main()
{
	int a=0x12131415,ch1,ch2,ch3,ch4;
	char *pa;
	pa=(char*)&a;
	ch1=*((char*)&a+4)=*((char*)&a+1);
	printf("%x",ch1);
	ch2=*((char*)&a+2)=*((char*)&a+3);
	printf("%x",ch2);
	ch3=*((char*)&a+2)=*((char*)&a+4);
	printf("%x",ch3);
	ch4=*((char*)&a+1)=*((char*)&a+3);
	printf("%x",ch4);

}
