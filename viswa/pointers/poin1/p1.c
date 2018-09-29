#include <stdio.h>
main()
{
	int a=300,i;
	char *p;
	p=&a;
	for (i=3;i>=0;i--)
	{
		printf("%d",*(p+i));
	}
}

