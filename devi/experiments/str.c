#include <stdio.h>
#include <string.h>
main()
{
	char str[]=	"\0";
	printf("%s\n",str);
	printf("%d\n", sizeof(str));
	printf("%d\n", strlen(str));
}
