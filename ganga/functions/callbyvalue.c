#include <stdio.h>

int  main()
{
	int a = 10, b = 20;
	printf("before swapping :%d, %d \n ", a, b);
	swap(a,b);

	return 0;
}

int swap(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	printf("after swapping :%d, %d \n ", a, b);
	
	return 0;
}
