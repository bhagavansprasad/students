#include <stdio.h>
main()
{
	int a=0x12131415;
	short int *sh1,*sh2;
	sh1=(short int *)&a;
	sh2=sh1+1;
		printf("%x\n",*sh1);
		printf("%x\n",*sh2);
}
