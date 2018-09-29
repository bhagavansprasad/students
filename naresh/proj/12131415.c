#include<stdio.h>
main()
{
	int a=0x12131415;
	char *pc=(char *)&a;
	int i=0,n=4;
	for(i=0;i<n;i++)
	{
		printf("%x",*pc);
		pc++;
	}
}
