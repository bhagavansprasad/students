#include <stdio.h>
#include <stdlib.h>

//int c[10] = {3,3,3,3,3,3,3,3,3,3};
//int a[10] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},i;
//int b[10] = {2,2,2,2,2,2,2,2,2,2};

main()
{
	int c[10] = {3,3,3,3,3,3,3,3,3,3};
	int a[10] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},i;
	int b[10] = {2,2,2,2,2,2,2,2,2,2};
	
	printf("enter elements:\n");
	for(i = -5; i < 0; i++)
	scanf("%d", &a[i]);
	
//	printf("entering\n");
//	for(i = -5;i < 0; i++)
//	scanf("%d", &a[i]);

	printf("Values in array A:\n");
	for(i = -5; i < 16; i++)
	printf("%d\t", a[i]);
	printf("\n");

	printf("Values in array C:\n");
	for(i = 0;i < 10; i++)
	printf("%d\t", c[i]);
	printf("\n");

	printf("Address  of C:\n");
	for(i = 0;i < 10; i++)
	printf("%u\t", &c[i]);
	printf("\n");
	
	printf("Address  of A:\n");
	for(i = -5; i < 16; i++)
	printf("%u\t", &a[i]);
	printf("\n");
	
	printf("Address  of B:\n");
	for(i = 0;i < 10; i++)
	printf("%u\t", &b[i]);
	printf("\n");
	
	}
