#include<stdio.h>
main()
{
	int arr[5]={10,20,30,40,50};
	int *p=&arr[5];
	printf("a[0] is : %d\n", arr[0]);
	printf("a[4] is : %d\n", arr[4]);
	printf("p is : %u\n", p);
}
