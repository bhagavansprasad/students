#include<stdio.h>
main()
{
	int a=0x12131415;
	char* pa;
	pa=(char*)&a;
	int temp1,temp2;
	printf("%x\n",a);
	temp1=*(pa+0);
	*(pa+0)=*(pa+3);
	*(pa+3)=temp1;
	temp2=*(pa+1);
	*(pa+1)=*(pa+2);
	*(pa+2)=temp2;
	printf("%x\n",a);
}	


