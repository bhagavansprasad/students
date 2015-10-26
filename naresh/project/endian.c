#include<stdio.h>
main()
{
	int a=300;
	char *p=(char *)&a;
	p[0];
		if(*p==44)
		{
			printf("little endian");
		}
		else
		{
			printf("big endian");
		}
}
