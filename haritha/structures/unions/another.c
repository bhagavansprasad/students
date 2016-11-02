#include <stdio.h>
#include<string.h>
union student
{
	char name[10];
	char grade;
	int age;
};
main()
{
	union student s,s1;
	strcpy(s.name,"thanu");
	printf("%s",s.name);
s1=s;
	printf("%s",s1.name);

		s.grade='A';

			printf("%c",s.grade);
			s1=s;
			printf("%c",s1.grade);

	s.age=10;


		printf("%d",s.age);
s1=s;
	printf("%d",s1.age);
//	printf("%c",s1.grade);
//	printf("%d",s1.age);
//	printf("%s",s.name);
//	printf("%c",s.grade);
//	printf("%d",s.age);
}
