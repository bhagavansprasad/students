#include<stdio.h>
#include<string.h>
main()
{
	struct student{
		int rn;
		char name[20];
		int age;
		char b;
		char a;
		int d;
	}stu1;
	struct student stu2={12,"rinju",25};
	stu1.rn=12;
	strcpy(stu1.name,"rinju");
	stu1.age=25;
	printf("%d ",stu1.rn);
	printf("%s ",stu1.name);
	printf("%d ",stu1.age);
	printf("%d ",stu2.rn);
	printf("%s ",stu2.name);
	printf("%d ",stu2.age);
	printf("%u",sizeof(stu1));

}
