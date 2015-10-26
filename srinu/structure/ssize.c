#include <stdio.h>
#include <string.h>
struct student
{
	char k;
//	int k;
	//short int a;
	char a;
	short int m;
//	char a;
	//int m;
	//char m;
};
main()
{
	struct student s;

		printf(" %d\n",sizeof(s));
       printf("%p %d\n",&s.k   ,  sizeof(s.k));
		printf("%p %d\n",&s.a    ,   sizeof(s.a));
		printf("%p %d\n",&s.m  , sizeof(s.m));
		//printf("%p %d\n",&s.l  , sizeof(s.l));
}
