#include <stdio.h>

main()
{
	int *a = 0x7fff4705b49c;
	*a = 10;
	printf("%d\n", *a);
}
