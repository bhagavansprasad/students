#include<stdio.h>
#include<string.h>
union student
{
//char name[20];
int age;
float marks;
};
main()
{
union student s;
{
//strcpy(s.name,"haritha");
//printf("%ld",sizeof(s.name));
s.age=20;
printf("%ld",sizeof(s.age));

s.marks=90;
printf("%ld",sizeof(s.marks));
printf("%ld",sizeof(s));

}
}
