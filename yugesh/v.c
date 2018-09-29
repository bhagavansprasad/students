#include <stdio.h>
main()
{
	int a=0X12131415;
	printf("%X\n",*((short*)&a));
	printf("%X\n",*((short*)&a+1));
}
