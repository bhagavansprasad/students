#include <stdio.h>
#include <stdlib.h>

main()
{
	int *ptr;

	sleep(10);
	ptr = malloc(10000000); 
	sleep(10);

	free(ptr);
}
