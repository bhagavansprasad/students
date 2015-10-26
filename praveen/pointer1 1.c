#include <stdio.h>
main()
{
	int i,a=300;
	char *p;
	p=&a;
	for(i=3;i>=0;i--)
	{
		printf("%d\t",*(p+i));
	}
	printf("\n");
}
