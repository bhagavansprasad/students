#include <stdio.h>
#include <string.h>
struct student
{
	short int a;
	short int b;
	//int m;
	int age;
	//char m;
	//int n;
	//char c;

}

main ()
{
	struct student s;

	printf ("%d\n", sizeof(s));

	printf ("%p   %d\n", &s.a,sizeof(s.a));
	printf ("%p   %d\n", &s.b,sizeof(s.b));
	printf ("%p   %d\n", &s.age,sizeof(s.age));
	//printf ("%p   %d\n", &s.c,sizeof(s.c));
}
