#include <stdio.h>
#include <string.h>
struct student
{
	char name[100];
	int age;
	int mark;
};

main ()
{
	struct student s = {"vinoth", 20, 90};
	printf ("%p\n",s.name);
	printf ("%p\n", &s.age);
	printf ("%p\n", &s.mark);
}
