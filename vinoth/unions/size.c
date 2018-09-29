#include <stdio.h>
#include <string.h>
union student
{
	//short int a;
	//short int b;
	//int m;
	//int a;
	char m;
	char n;
	//int n;
	char c;

}

main ()
{
	union student s;

	printf ("%d\n", sizeof(s));

	printf ("%p   %d\n", &s.m,sizeof(s.m));
	printf ("%p   %d\n", &s.n,sizeof(s.n));
	printf ("%p   %d\n", &s.c,sizeof(s.c));
	//printf ("%p   %d\n", &s.c,sizeof(s.c));
}
