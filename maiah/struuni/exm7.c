#include "stdio.h"
#include "string.h"
struct stu
{
	char name[20];
	int marks;
	int rollno;
};
int marks(struct stu s[]);
void display(struct stu s[]);
main()
{
	struct stu s[3]={
						{"venky",90,21},
						{"gautam",80,20},
						{"vijju",80,19}
					};
	int i;
	marks(s);
	for(i=0;i<3;i++)
	display(s[i]);
	return 0;
}
int marks(struct stu s[])
{
	int i;
	for(i=0;i<3;i++)
	{
		s[i].marks=s[i].marks-12;
		return s[i].marks;
	}
}
void display(struct stu s[])
{
	printf("%s\n",stu.name);
	printf("%d\n",stu.marks);
	printf("%d\n",stu.rollno);
}
