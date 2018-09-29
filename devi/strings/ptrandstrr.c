#include <stdio.h>
main()
{
	char *ptr = "Aura Networks";
	char str[] = "AuraNetworks";

	printf("ptr = %s\n", ptr);
	printf("str = %s\n", str);
	printf("ptr = %u\n", ptr);
	printf("str = %u\n", str);

	//ptr++;
	//printf("ptr = %u\n", ptr);
	//printf("ptr = %s\n", ptr);

	//str++;
	//printf("str = %u\n", str);

	str[1] = 'A';
	printf("str = %s\n", str);

	//ptr+1 = 'A';
	//printf("ptr = %s\n", ptr);
}
