#include <stdio.h>
struct student
{
	char name[10];
	int age;
	float marks;
}
main()
{
	struct student s,*p;
	{
		p=&s;
		strcpy(p->name,"hari");
		printf("%s",p->name);
		//printf("%d",p->age=20);
		//printf("%f",p->marks=90);
	}
}

