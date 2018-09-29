#include <stdio.h>
main()
{
	int a=0x12131415 , sh1 , sh2 ;
	short int *p=(short int*)&a;
	sh1=*(p+1);
	sh2=*p;
	printf("0x%x\n",sh1);
	printf("0x%x\n",sh2);
}
