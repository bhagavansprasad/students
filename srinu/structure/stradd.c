#include <stdio.h>
#include <string.h>
struct student
{
	char name[100];
	unsigned int age;
	int marks;
};
main()
{
	struct student s={"thanu",5,90};

		printf("%p %d\n",  &s      ,       sizeof(s));
		printf("%p %d\n",&s.name   ,  sizeof(s.name));
		printf("%p %d\n",&s.age    ,   sizeof(s.age));
		printf("%p %d\n",&s.marks  , sizeof(s.marks));
}
