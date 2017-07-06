#include "stdio.h"

main()
{
	int a = 0x12131415;
	int i = 0;

	for (i = 0; i <= 3; i++)
		printf("%p:%p\n", ((char *)&a + i), *((char *)&a + i));

	printf("\n");

	printf("%x\n", *(((short *)&a) + 0));
	printf("%x\n", *(((short *)&a) + 1));
}
