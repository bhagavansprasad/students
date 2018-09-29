#include <stdio.h>
#include <string.h>
struct student
{
	char name[10];
	int age;
	int mark;
};

main ()
{
	struct student s1 = {"VINOTH", 20, 100}, s2;
		printf ("%s\n", s1.name);
		printf ("%d\n", s1.age);
		printf ("%d\n", s1.mark);
		s2=s1;
		printf ("%s\n", s2.name);
		printf ("%d\n", s2.age);
		printf ("%d\n", s2.mark);
}
