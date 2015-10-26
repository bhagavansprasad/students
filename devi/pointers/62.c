#include <stdio.h>
main()
{
	int a = 0x12131415;
	char ch1,ch2,ch3,ch4;
	char *c;
	c=&a;
	ch1=*(c+3);
	printf("0x%x\n",ch1);
		//	c++;
	ch2=*(c+2);
	printf("0x%x\n",ch2);
	//	c++;
	ch3=*(c+1);
	printf("0x%x\n",ch3);
	//	c++;
	ch4=*c;
	printf("0x%x\n",ch4);
}
