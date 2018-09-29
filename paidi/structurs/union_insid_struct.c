#include <stdio.h>

    union id 
	{
		char name[40];
		int number;
	};

	struct id2
	{
		int salary;
		union id description;
	} student,*faculty;

int main ()
{
    struct id2 student;  
    faculty = &student;
	faculty->salary = 12;
	printf("%d\n",faculty->salary);
//	strcpy(faculty->name,"Sam");
//    faculty->number = 10;
//	printf("%d\n",faculty->number);
}

