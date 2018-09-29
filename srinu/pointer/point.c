#include<stdio.h>
int main()
{
	int a=0x12131415;
	int i,n=4;
	char *cp=&a;
	short *sp=&a;
	int *ip=&a;
	for(i=0;i<n;i++)
	{
		printf("%x\n",*cp);
		printf("%x\n",*sp);
		printf("%x\n",*ip);
		cp++;
		sp++;
	}
}
