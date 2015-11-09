#include<stdio.h>
#include<string.h>
union student
{
	char name[10];
	int age;
	int marks;
};
main()
{
	union student s;
	{
		strcpy(s.name,"thanu");
		printf("%p\n",s.name);
		s.age=10;
		printf("%p\n",&s.age);
		s.marks=90;
		printf("%p\n",&s.marks);
		printf("%p\n",&s);
	}
}
