#include <stdio.h>
main()	
{
	int a=0x12345678,b=0x00000000;
	*(((char*)&b)+3)=*(((char*)&a)+2);
	*(((char*)&b)+2)=*(((char*)&a)+3);
	*(((char*)&b)+1)=*(((char*)&a)+0);
	*(((char*)&b)+0)=*(((char*)&a)+1);
	printf("B:0x%x",b);
}
