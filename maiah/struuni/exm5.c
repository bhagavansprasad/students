#include "stdio.h"
#include "string.h"
struct student
{
	char name[30];
	int rollno;
	int marks;
};
void inc_marks(struct student *p);
void display(struct student *p);
main()
{
	struct student s;
	strcpy(s.name,"venky");
	s.rollno=21;
	s.marks=45;
	inc_marks(&s);
	display(&s);
	return 0;
}
void inc_marks(struct student *p)
{
	(p->marks)++;
}
void display(struct student *p)
{
	printf("%s\n",p->name);
	printf("%d\n",p->rollno);
	printf("%d\n",p->marks);
}

