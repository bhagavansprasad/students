#include<stdio.h>

main()
{
	int a = 4, b = 10;
	printf("Before swaping a = %d   b = %d \n",a,b);
	
	a = a + b;
	b = a - b;
	a = a - b;
	printf("After swaping a = %d   b = %d \n", a, b);
}
	
