#include "stdio.h"
#include "string.h"
struct student
{
	char name[25];
	int rollno;
	float marks;
};
main()
{
	struct student stu1;
	strcpy(stu1.name,"venkatesh");
	stu1.rollno=221;
	stu1.marks=9;
	
	printf("name:%s\n rollno:%d\n marks:%f\n",stu1.name,stu1.rollno,stu1.marks);
	printf("%u\n%u\n%u\n",stu1.name,&stu1.rollno,&stu1.marks);
	printf("%d\n%d\n%d\n",sizeof(stu1.name),sizeof(stu1.rollno),sizeof(stu1.marks));	
	
	struct student stu2;
	strcpy(stu2.name,"hanumanthu");
	stu2.rollno=242;
	stu2.marks=8;
	
	printf("name:%s\n rollno:%d\n marks:%f\n",stu2.name,stu2.rollno,stu2.marks);
	printf("%u\n%u\n%u\n",stu2.name,&stu2.rollno,&stu2.marks);
	printf("%d\n%d\n%d\n",sizeof(stu2.name),sizeof(stu2.rollno),sizeof(stu2.marks));
	
	struct student stu3;
	strcpy(stu3.name,"harish");
	stu3.rollno=220;
	stu3.marks=8;
	
	printf("name:%s\n rollno:%d\n marks:%f\n",stu3.name,stu3.rollno,stu3.marks);
	printf("%u\n%u\n%u\n",stu3.name,&stu3.rollno,&stu3.marks);
	printf("%d\n%d\n%d\n",sizeof(stu3.name),sizeof(stu3.rollno),sizeof(stu3.marks));

	printf("%d\n",sizeof(struct student));

	return 0;
}
