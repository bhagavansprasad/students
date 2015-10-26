#include <stdio.h>
main()
{
	int a=0x12131415,i,n=4;
	char *p=(char *)&a;
	p=p+3;
	for(i=0;i<n;i++)
	{
		printf("%x",*p);
		p--;
	}
}
