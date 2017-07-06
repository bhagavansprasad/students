#include<stdio.h>
#include<string.h>
typedef struct stu
{
	int age;
	char name[20];
}stud;

main()
{
	stud stu1={12,"bapi"};
	stud stu2;
	stu2.age=15;
	strcpy(stu2.name,"rinju");
	printf("%d %s",stu1.age,stu1.name);
	printf("%d %s",stu2.age,stu2.name);
}
