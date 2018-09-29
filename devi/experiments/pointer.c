#include <stdio.h>
main()
{
	int a=10;
	int *pa=&a;
	char ch='a';
	char *pch=&ch;
	printf("%u %u\n",pa,pch);
	pa++;
	pch++;
	printf("%u %u\n",pa,pch);
}
