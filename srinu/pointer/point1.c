#include<stdio.h>
int main()
{
	int a=0x12131415;
	int i;
	char *cp=&a;
	short *sp=&a;
	int *ip=&a;
	for(i=4;i>0;i--)
	{
		printf("%x\n",*cp);
		cp++;
		printf("%x\n",*sp);
		sp++;
		printf("%x\n",*ip);
	}
}
