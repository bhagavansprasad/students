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
{
		printf("%ld\n",sizeof(s));
		printf("%ld\n",sizeof(s.name));
		printf("%ld\n",sizeof (s.age));
		printf("%ld\n",sizeof (s.marks));
		//printf("%d",sizeof (s.age));

	}
}
