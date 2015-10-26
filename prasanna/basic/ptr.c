#include<stdio.h>

main()
{
	int a = 10, *ptr;
	ptr = &a;

	printf(" %d\n  %d\n",++*ptr, (*ptr)++);
}
