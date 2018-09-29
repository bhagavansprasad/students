#include <stdio.h>

main()
{
	char *p;

	printf("address of p is %p\n", p);
	printf("value of p is %p\n", p);
	printf("seize of p is %d\n", sizeof(p));

	strcpy(p, "ANetworks");
	printf("%s\n", p);

	printf("address of p is %p\n", p);
	printf("value of p is %p\n", p);
	printf("seize of p is %d\n", sizeof(p));
}
