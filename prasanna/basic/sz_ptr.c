#include <stdio.h>

main()
{
	char *p;
	int b;

	int *ptr;
	printf("Sizeof int %ld\n",sizeof(b));
	printf("%ld  %ld  %ld\n",sizeof(*p), sizeof(p), sizeof(ptr));
}
