#include <stdio.h>
#include <stdlib.h>

main()
{
	//char *p = "sai";
	char *p = (char *)malloc(10);
	printf("%p\n", p);
    *(p+1) = 'a';
	printf("---> contrnt in p %c\n", *(p+1));

	free(p);

	return 0;
}
