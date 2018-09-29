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
	int i;
	union student s;
	strcpy(s.name,"vinoth");
	printf ("%s\n", s.name);
	s.age = 23;
	printf ("%d\n", s.age);
	s.mark = 100;
	printf ("%d\n", s.mark);
}
