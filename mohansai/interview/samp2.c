#include "stdio.h"
main()
{
	char *p;
	char c = 'a';
	p=&c;

	printf("-->c sizeof  %d\n\r", sizeof(c));
	printf("-->a sizeof  %d\n\r", sizeof('a'));
	printf("-->*p sizeof %d\n\r", sizeof(*p));
	printf("-->p sizeof  %d\n\r", sizeof(p));
}
