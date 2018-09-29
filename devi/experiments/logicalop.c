#include <stdio.h>
main()
{
	int a=10,b=20,c=0,n=0;
	n = ++a && ++b || ++c;
	printf("a=%d\t b=%d\t c=%d \tn=%d\t",a,b,c,n);
}
