#include <stdio.h>
#include "string.h"
main()
{
	char str[15]="aura networks";
	printf("%u\n",str);
	printf("%u\n",&str);
	printf("%u\n",str+1);
	printf("%u\n",&str+1);
	printf("%u\n",*&str);
	printf("%u\n",*str);
	printf("%u\n",**&str);
}
