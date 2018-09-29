#include <stdio.h>
main()
{
	int a=0x12131415;
	char *p=(char *)&a;
	p=p+3;
	int i,n=4;
	for(i=0;i<n;i++)
	{
		printf("%x\n",*p);
		p--;
	}
}
