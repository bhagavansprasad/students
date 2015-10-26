#include <stdio.h>
main()
{
	int a=0x12345678;
	int *p=&a;
	int a1,a2,a3,a4;

	a1=(*(char*)p);
	printf("%x\n",a1);
	a2=*((char*)p+1);
	printf("%x\n",a2);
	a3=*((char*)p+2);
	printf("%x\n",a3);
	a4=*((char*)p+3);
	printf("%x\n",a4);
	return 0;

}

