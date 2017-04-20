#include <stdio.h>
main()
{
	int a = 12131415;
	char *cp = &a;

	if(cp[0] == 15)
	{
		printf("your system is big endian");
	}
	
	else
	{
		printf("your system is little endian");
	}
}
