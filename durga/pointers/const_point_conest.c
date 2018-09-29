#include <stdio.h>
main()
{
	int a = 5, b = 6;
	const int* const p = &a ;
	printf("%d\n",*p);
	*p = 9;
	printf("%d\n",*p);
}
