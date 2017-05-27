#include <stdio.h>
main()
{
	int a=0x10,b=0xa;
	a=a^b;
	b=a^b;
	a=a^b;
	printf("%d\n",a);
	printf("%d\n",b);
}
