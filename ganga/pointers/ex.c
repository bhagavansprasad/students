#include <stdio.h>

main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int *ip = &a;

	printf("sizeof this array is : %d \n", (int)(&a+1) - (int)(&a));
}
