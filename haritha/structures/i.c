#include<stdio.h>
#include<string.h>
struct student
{
	//char name[10];
	unsigned int age;
	int marks;
};
main()
{
	struct student s;
	{
		s.age=5;
		s.marks=90;
		printf("%ld",sizeof(s));
		printf("%ld",sizeof(s.age));
		printf("%ld",sizeof(s.marks));
	}
}
