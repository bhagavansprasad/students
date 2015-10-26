#include<stdio.h>
main()
{
	int a=0x12131415;
	int i,n=4;
	char *pc=(char *)&a;
	for(i=0;i<n;i++)
	{
	printf("%x\n",*pc);
	pc++;
	}
}

