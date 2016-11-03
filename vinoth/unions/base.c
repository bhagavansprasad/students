#include <stdio.h>
#include <string.h>

union student
{
	char name[100];
	int age;
	int mark;
};

main()
{
	union student s;
	strcpy(s.name,"vinoth");
	printf("%p\n", s.name);
	s.age = 23;
	printf ("%p\n", &s.age);
	s.mark = 100;
	printf ("%p\n", &s.mark);
}
