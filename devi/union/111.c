#include <stdio.h>
union std
{
	int a;
	char b;
	short int c;
};

int main()
{
	union std s1 = {10,'a',34};
	union std s2;
	s2 = s1;
	printf("size of union=%d\n", sizeof(s1));
	printf("size of union=%d\n", sizeof(s2));
	printf("address of int %u\n",&(s1.a));
	printf("address of int %u\n",&(s1.b));
	printf("address of int %u\n",&(s1.c));
	return 0;
}
