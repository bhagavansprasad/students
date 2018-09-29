#include <stdio.h>
main()
{
	int a=0x12131415,temp;
	char*pa;
	pa=(char)&a;
	temp=*((short*)&a);
	*((short*)&a)=*((short*)&a+1);
	*((short*)&a+1)=temp;
	printf("%x",a);
}

