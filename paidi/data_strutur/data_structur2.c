#include<stdio.h>
#include<string.h>
main()
{

 struct name_student 
{
char name[5];
int class;
int marks;
int age;
};

struct name_student s1;
strcpy(s1.name,"paidi");
 s1.class=1;
 s1.marks=66;
 s1.age=22;
printf("%s\n",s1.name);

//printf("name***********=%s\n",b);
printf("class***********=%d\n",s1.class);
printf("marks***********=%d\n",s1.marks);
printf("age*************=%d\n",s1.age);
 
}
