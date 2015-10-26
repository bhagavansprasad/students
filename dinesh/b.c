#include<stdio.h>
main ()
{
	int a[5] = {1,2,3,4,5};
	printf("%u\n",a);
	printf("%u\n",&a+1);	
	printf("%d\n",&a+1-a);
}
