#include <stdio.h>
main()
{
	int a=0x12131415 , ch1 , ch2 , ch3 , ch4,temp;
	char *p=(char*)&a;
	ch1=*(p+3);
	ch2=*(p+2);
	ch3=*(p+1);
	ch4=*p;

	temp=ch4;
	ch4=ch1;
	ch1=temp;
	temp=ch3;
	ch3=ch2;
	ch2=temp;
	printf("0x%x",ch1);
	printf("%x",ch2);
	printf("%x",ch3);
	printf("%x\n",ch4);
}
