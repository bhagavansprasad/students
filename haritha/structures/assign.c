#include<stdio.h>
#include<string.h>
struct student
{
	char name[10];
	 int age;
	int marks;
};
main()
{
	struct student s1={"haritha",20,90},s2;
	{
		
		printf("%s\n",s1.name);
		printf("%d\n",s1.age);
		printf("%d\n",s1.marks);
		s2=s1;
		printf("%s",s2.name);
		printf("%d",s2.age);
		printf("%d",s2.marks);
	}
}
