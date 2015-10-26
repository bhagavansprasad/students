#include<stdio.h>
main()
{
	int a = 0x12131415, i;
	short int *sh1, *sh2;
	char *p;
	sh2 = *(short int*)&a;
	sh1 =*(( (short int*)&a)+1);
	printf("%x\n%x",sh1,sh2);
	}

