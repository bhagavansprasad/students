#include "stdio.h"
#include "defs.h"

main()
{
	int i = 0;

	printf("The MAX value is :%d\n", MAX_VALUE);

	for (i = 1; i <= MAX_VALUE; i++)
		printf ("%d ", i);

	printf ("\n");
}
