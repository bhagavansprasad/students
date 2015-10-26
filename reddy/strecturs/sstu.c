#include "stdio.h"
#include "string.h"
struct student
{
char name[20];
int rollno;
float marks;
};
main()
{
struct student stu1={"mary",59,45};
struct student stu2,stu3;
strcpy(stu2.name,"reddy");
stu2.rollno=60;
stu2.marks=75;
stu3=stu2;
printf("%s%d%f\n",stu1.name,stu1.rollno,stu1.marks);
printf("%s%d%f\n",stu2.name,stu2.rollno,stu2.marks);
printf("%s%d%f\n",stu3.name,stu3.rollno,stu3.marks);
printf("%ld%ld%ld\n",sizeof (stu1.name),sizeof (stu1.rollno),sizeof (stu1.marks));
return 0;
}
