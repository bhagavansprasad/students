#include <stdio.h>
main()
{
	int a=0x12131415 , ch1 , ch2 , ch3 , ch4;
	char *p=(char*)&a;
	ch1=*(p+3);
	ch2=*(p+2);
	ch3=*(p+1);
	ch4=*p;
	printf("0x%x\n",ch1);
	printf("0x%x\n",ch2);
	printf("0x%x\n",ch3);
	printf("0x%x\n",ch4);
}
