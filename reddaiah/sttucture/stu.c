#include"stdio.h"
#include"string.h"
struct student
{
	char name[100];
	char fname[100];
	char gender[20];
	int roll;
	int marks;
};
int main()
{
	struct student st1;
	strcpy(st1.name,"reddaiah");
	strcpy(st1.fname,"subramanyam");
	strcpy(st1.gender,"male");
	st1.roll=4461;
	st1.marks=450;
	printf("<name>%s\n<fname>%s\n<gender>%s\n<roll>%d\n<marks>%d\n",st1.name,st1.fname,st1.gender,st1.roll,st1.marks);
	printf("total %ld\n",sizeof(struct student));
	printf("%d\n",sizeof (char));
	printf("sizeof name %d\n",sizeof st1.name);
	printf("sizeof fname %d\n",sizeof st1.fname);
	printf("sizeof gender %d\n",sizeof st1.gender);
	printf("sizeof roll %d\n",sizeof st1.roll);
	printf("sizeof marks %d\n",sizeof st1.marks);
	printf("<fname %d\n>",&(st1.fname));
	printf("<name %d\n>",&(st1.name));
	printf("<roll %d\n>",&(st1.roll));
	printf("<gender %d\n>",&(st1.gender));
	printf("<marks %d\n>",&(st1.marks));
	return 0;
}
