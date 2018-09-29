#include <stdio.h>
struct student
{
	int marks;
	char name[100];
	float percentage;
	int a;
	int b;
};
int main()
{
	struct student s1={0};
	/*s1.a=4;
	s1.b;
	s1.marks = 55;
	s1.percentage = 85;
	strcpy(s1.name,"kiran");*/
	s1.b=s1.a;
	printf("a == %d\n",s1.a);
	printf("b == %d\n",s1.b);
	printf("name == %s\n",s1.name);
	printf("marks == %d\n",s1.marks);
	printf("percentage == %f\n",s1.percentage);
}
