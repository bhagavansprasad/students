#include <stdio.h>
main()
{
	int a = 10, b, x , y, z;
	x = a--;
	y = --a;
	z = ++a;
	b = a++;
	printf("x :%d\n", x);
	printf("y :%d\n", y);
	printf("z :%d\n", z);
	printf("b :%d\n", b);
	printf("--a :%d\n", --a);
	printf("++a :%d\n", ++a);
	printf("a-- :%d\n", a--);
	printf("a++ :%d\n", a++);
}
