#include<stdio.h>
main()
{
	char a[15]="aura networks";

	printf("%p\n",a);
	printf("%p\n",a+1);
	printf("%p\n",&a+1);

}
