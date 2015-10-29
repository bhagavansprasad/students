#include <stdio.h>
main()
{
	int a = 0x12131415;
	char *cp = (char*)&a;
	if(*cp == 0x15)
		printf("little");
	else
		printf("big");
}
