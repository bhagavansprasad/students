#include<stdio.h>
main()
{
	int a = 0x12131415, i;
	char *ch;
	ch = (char*)&a;
	for(i = 0; i<4; i++,ch++)
	{
	printf("%x\n",*ch);
	}
	}
