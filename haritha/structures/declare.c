#include<stdio.h>
#include<string.h>
struct student
{
	char name[10];
	unsigned int age ;
	int marks;
};

main()
{
	struct student s;
	strcpy(s.name,"haritha");
	s.age=20;
	s.marks=90;
	printf("%s\n",s.name);
	printf("%d\n",s.age);
	printf("%d\n",s.marks);
}
