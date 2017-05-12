#include "stdio.h"

struct student_data
{
	int age;
	int class;
};

main()
{
	int a;
	struct student_data sdata;

	sdata.age = 20;
	sdata.class = 9;

	printf ("stu age   :%d\n", sdata.age);
	printf ("stu class :%d\n", sdata.class);
}



