#include"stdio.h"
#include"string.h"
struct student
{
short rollno;
char name[45];
float marks;
};
main()
{
struct student stu1={25,"lokesh",68};
struct student stu2,stu3;
strcpy (stu2.name,"lok");
stu2.rollno=68;
stu2.marks=98;
stu3=stu2;
printf("%s %d %f\n",stu1.name,stu1.rollno,stu1.marks);
printf("%u %u %u\n",&stu1.rollno,stu1.name,&stu1.marks);
printf("%s %u %p\n",stu2.name,&stu2.rollno,&stu2.marks);
printf("%s %u %p\n",stu3.name,&stu3.rollno,&stu3.marks);
printf("%d %d %d\n",sizeof(stu1.name),sizeof(stu1.rollno),sizeof(stu1.marks));
printf("%d\n",sizeof(struct student));
return 0;
}

