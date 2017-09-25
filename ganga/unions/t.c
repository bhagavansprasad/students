#include "stdio.h"

union t
{
	char ar[4];
	int a;
};

union t x = {"abcd"};

main()
{
	int i = 0;
	char arr[10] = {'a', 'b', 'c', '\0'};

	for (i = 0; i <=3 ; i++)
		printf ("%p: %d\n", ((char *)&(x.a))+i, *(((char *)&(x.a))+i));

	printf("\n");

	for (i = 0; i <=3 ; i++)
		printf ("%p: %d\n", &(x.ar[i]), x.ar[i]);

	printf("arr :%s\n", arr);
}
