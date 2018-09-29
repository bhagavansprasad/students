#include <stdio.h>
main()
{

union test1
{
	float a;
	int d,b;
	char c;
};

struct test2
{
	float a;
	int c,b;
	char d;
};

union test1 t1;
struct test2 t2;

printf("union size-->%ld, Structure Size-->%ld\n",sizeof(t1),sizeof(t2));
}
