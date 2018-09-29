#include <stdio.h>
#include <string.h>

struct student 
{
	int id;
	char name[30];
	float percentage;
};

int main() 
{
    struct student record1 = {1, "paidi", 90.5};

	printf("Records of STUDENT1: \n");
	printf("  Id is: %d \n", record1.id);
	printf("  Name is: %s \n", record1.name);
	printf("  Percentage is: %f \n\n", record1.percentage);
	return 0;
}
