#include"stdio.h"
#include"string.h"
struct student
{
char personality[44];
short rollno;
char name[4];
char month[10];
};
main()
{
struct student stu1={"good",25,"lokesh","july"};
struct student stu2,stu3;
strcpy(stu2.personality,"good");
strcpy (stu2.name,"lok");
stu2.rollno=68;
strcpy(stu2.month,"july");
struct student *p=&stu1;
stu3=stu2;
printf("%s %s %d %s\n",stu1.personality,stu1.name,stu1.rollno,stu1.month);
printf("%u %u %u %u\n",stu1.personality,&stu1.rollno,stu1.name,stu1.month);
printf("%s  %s %u %s\n",stu2.personality,stu2.name,&stu2.rollno,stu2.month);
printf("%s %s %u %s\n",stu3.personality,stu3.name,&stu3.rollno,stu3.month);
printf("%d %d %d %d\n",sizeof(stu1.personality),sizeof(stu1.rollno),sizeof(stu1.name),sizeof(stu1.month));
printf("%s %s %d %s\n",p->personality,p->name,p->rollno,p->month);
printf("%d\n",sizeof(struct student));
return 0;
}

