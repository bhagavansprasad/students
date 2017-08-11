#include <stdio.h>
main()
{
	int a[5] = { 0, 1, 2, 3, 4}, size = 0;
//	printf("a : %p \n &a : %p\n a[0] : %d\n &a[0] : %d\n a++ : %d\n &a++ %p\n", a, &a, a[0], &a[0], a + 1, &a + 1);
	size = (int)((&a) + 1 - &a);
	printf("size is  %d\n", size);
}
