#include <stdio.h>

main()
{
	char p[20];
	printf("%p\n", p);
	printf("%d\n", p);
	printf("size of p is %d \n", sizeof(p));

	strcpy(p, "ANetworks\n");

	printf("%s\n", p);
	
	printf("%p\n", p);
	printf("%d\n", p);
	printf("size of p is %d \n", sizeof(p));
}
