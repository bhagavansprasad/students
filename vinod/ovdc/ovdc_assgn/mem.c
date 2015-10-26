#include <stdlib.h>
main()
{
	int *ptr;
	
	sleep(10);
	ptr = malloc(100000);
	sleep(10);

	free(ptr);
}
