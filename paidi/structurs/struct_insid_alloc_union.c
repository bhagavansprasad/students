#include <stdio.h>
#include <string.h>

struct student_college_detail
{
    int college_id;
    char college_name[50];
};

union student_detail 
{
    int id;
    char name[40];
    int num;
    struct student_college_detail clg_data;   // structure within structure
}stu_data, *ptr;

int main() 
{
    union student_detail stu_data;
    ptr = &stu_data;

    ptr->id = 2;
    printf(" Id is: %d \n", ptr->id);
	strcpy(ptr->name,"Paidi");
    printf(" Name is: %s \n",ptr->name);
    ptr->num = 9;
    printf(" num is: %d \n\n", ptr->num);

    printf(" Id is: %d \n", ptr->id);
	printf(" Name is: %s \n",ptr->name);
    printf(" num is: %d \n\n", ptr->num);
    return 0;
}
