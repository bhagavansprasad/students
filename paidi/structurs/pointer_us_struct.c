#include <stdio.h>
#include <string.h>

struct student 
{
	int id;
	char name[30];
	float percentage;
};
struct student record1 = {1, "Raju", 90.5};

int main() 
{
	int i;
	struct student *ptr;
	ptr = &record1;     

	printf("Records of STUDENT1: \n");
	printf("  Id is: %d \n", ptr->id);
	printf("  Name is: %s \n", ptr->name);
	printf("  Percentage is: %f \n\n", ptr->percentage);
	return 0;
}
