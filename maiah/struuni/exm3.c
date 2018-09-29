#include "stdio.h"
#include "string.h"
struct student
{
	char name[20];
	int rollno;
	float marks;
};
void display(char name[],int rollno,float marks);
main()
{
	struct student s1;
	strcpy(s1.name,"venkatesh");
	s1.rollno=221;
	s1.marks=88;
	display(s1.name,s1.rollno,s1.marks);
	return 0;
}
void display(char name[],int rollno,float marks)
{
	printf("%s\n",name);
	printf("%d\n",rollno);
	printf("%f\n",marks);
}
