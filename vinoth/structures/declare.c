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
	struct student s = {"vinoth", 20,90};

	printf ("%s\n",s.name);
	printf ("%d\n",s.age);
	printf ("%d\n",s.mark);
}

