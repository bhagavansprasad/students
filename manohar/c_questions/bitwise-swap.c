#include <stdio.h>
main()
{
	int a=10,b=20;
	a=a^b;
	b=a^b;
	a=a^b;
	printf("a value:%d\nb value:%d\n",a,b);
}
