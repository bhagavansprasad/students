#include "stdio.h"
#include "string.h"
struct student
{
	char c;
	char r;
	char a[5];
	char w;
	short int d;	
};
main()
{
	struct student stu1;
	printf("%d\n",sizeof(struct student));

	return 0;
}

