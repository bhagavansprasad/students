#include "stdio.h"
#include "string.h"
struct emp
{
	char name[29];
	int age;
	int salary;
	char company[30];
}
main()
{
	struct emp e;
	strcpy(e.name,"ramu");
	e.age=27;
	e.salary=30000;
	strcpy(e.company,"silk house");
}
