#include <stdio.h>
main()
{
	int *a[10];	//array of pointers	
	int (*b)[10];	//pointer to an array
	int c[2] = {1,2};
	int val1 = 1;
	int val2 = 2;
	printf("sizze of an array int *a[2]  = %d\n", sizeof(a));
	printf("size of ptr to an arr of int (*b)[2] = %d\n", sizeof(b));
	printf("size of an array c[2] = %d\n", sizeof(c));
	a[0] = &val1;
	a[1] = &val2;

	printf("%p\n", a);
	printf("%p\n", a+1);
	printf("\n\naddress of int a[0] = %u value at that addr = %d\n", a[0],*a[0]);
	printf("address of int a[1] = %u value at that addr = %d\n", a[1],*a[1]);

	printf("\n\naddress of int c[0] = %u value at that addr = %d\n", &c[0],c[0]);
	printf("address of int c[1] = %u value at that addr = %d\n", &c[1],c[1]);

	b = (int *)&c;
	printf("\n\npointer b= %u value at addr is c *b = %u\n",b,*b);
	printf("address of int b[0] = %u value at that addr = %d\n",&b[0],*b[0]);
	printf("address of int b[1] = %u value at that addr = %d\n",&b[1],*b[1]);

	//int *p = *(*a[0]);
	//printf("%p\n", p);
	return 0;
}
