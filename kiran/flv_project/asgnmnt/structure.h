#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


typedef struct student
{
	char name[124];
	int age;
	int class;
}record1;

typedef struct student2
{
	char name[124];
	char grade;
	int marks;
	int age;
	int class;
}record2;
