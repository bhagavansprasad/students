#include <stdio.h>
struct student
{
	char name[10];
	int age;
	float marks;
};
main()
{
	struct student s = {"thanu", 5, 90};

	printf("%p\n", &s);
	printf("%p\n", s.name);
	printf("%p\n", &s.age);
	printf("%p\n", &s.marks);

}
