#include<stdio.h>
main()
{
	union size
	{
		//int a;
		char ch;
		//float f;
		//int b;
		char ch1;
		char ch2;
		short sh;
		short sh1;
		//double d;
	}size;
	printf("size of union is : %ld\n", sizeof(size));
}

