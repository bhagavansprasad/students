#include<stdio.h>
main()
{
	int a=0x12131415;
	int i=0,n=4;
	char *pc;
	pc = (char *)&a;
	for(i=n;i>0;i--)
	{
		pc=pc+i;
		printf("%X\n",*pc);
		printf("%u\n",pc);
		}
}
