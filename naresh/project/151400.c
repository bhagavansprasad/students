#include"stdio.h"
main()
{
	int a=0x12131415;
	char *pc=(char *)&a;
	int i=0,n=4;
	pc=pc+3;
	*pc=0;
	pc=pc-1;
	*pc=0;
	pc=pc-2;
	for(i=0;i<n;i++)
	{
		printf("%x",*pc);
		pc++;
}
}
