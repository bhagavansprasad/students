#include <stdio.h>
struct student
{
	char name[10];
	int age;
	int marks;
}
main()
{
	struct student s={"sreenu",25,78},*p;
	{
		p=&s;
		printf("%s\n",p->name);
		printf("%d\n",p->age);
		printf("%d\n",p->marks);
	}
}

