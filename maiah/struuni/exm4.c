#include "stdio.h"
#include "string.h"
struct emp
{
	char name[30];
	int age;
	float salary;
};
	void display(struct emp e);
main()
{
	struct emp e;
	strcpy(e.name,"sirisha");
	e.age=21;
	e.salary=40000;
	display(e);
	return 0;
}
void display(struct emp e)
{
	printf("%s\n",e.name);
	printf("%d\n",e.age);
	printf("%f\n",e.salary);
}
