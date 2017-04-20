#include <stdio.h>

main()
{
	int i = 10;
	printf("%d %u\n", i, &i);
	
	&i = 7200;
	printf("%d %u\n", i, &i);
}
