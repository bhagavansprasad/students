#include <stdio.h>
main()
{
	int a = 0x12131415;
	short int sh1,sh2;
	short int *s;
	s = (short int *)&a;
	sh1 = *s;
	s++;
	sh2 = *s;
	printf("%x addr---->%u\n",sh2,&sh2);
	printf("%x addr---->%u\n",sh1,&sh1);
}
