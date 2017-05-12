#include <stdio.h>

main()
{
	char arr[20];
	char *p;

	printf("---> address of p %p\n", &p);
	printf("---> value of p %p\n", p);
	printf(" --> size of p is %d\n", sizeof(p));
	printf("---> address of arr is %p\n", arr);
	printf(" --> size of arr is %d\n", sizeof(arr));

	p = arr;

	strcpy(p, " ANetworks");
	printf("%s\n", p);

	printf("---> address of p %p\n", &p);
	printf("---> value of p %p\n", p);
	printf("---> address of arr is %p", arr);
	printf(" --> size of p is %d\n", sizeof(p));
	printf(" --> size of arr is %d\n", sizeof(arr));
}
