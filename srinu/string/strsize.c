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
	struct student s={"sreenu",5,90};

	printf("%d\n",sizeof(s));
	printf("%d\n",sizeof(s.name));
	printf("%d\n",sizeof (s.age));
	printf("%d\n",sizeof (s.marks));
}
