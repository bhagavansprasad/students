#include <stdio.h>

main()
{
	int arr[3][4] = {1, 2, 3, 4,
					5, 6, 7, 8,
					9, 10, 11, 12};
	int (*ptr)[4];
	ptr = arr;
	printf("%d\n", ptr[3][2]);
}
