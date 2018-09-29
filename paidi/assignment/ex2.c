#include<stdio.h>
#include<stdlib.h>
#include <string.h>

union employee
{
    char name[15];
    int age;
    float salary;
};
union employee e1;


int main()
{
    strcpy(e1.name, "paidi");
    printf("string :%s\n", e1.name);
	e1.age    = 20;
    printf("age    :%d\n",e1.age);
	e1.salary = 60.60;
    printf("salary :%f\n",e1.salary);
    //printf("%s %d %f", e1.name, e1.age, e1.salary);
    return 0;
}

