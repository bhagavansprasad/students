#include<stdio.h>
struct student
{
//	int a;
     char b;
	 int d;
//	 char c;
}
main()
{
	struct student s={30,40};
	printf("%ld",sizeof(s));
//	printf("%ld",sizeof(s.a));
	printf("%ld",sizeof(s.b));
//	printf("%ld",sizeof(s.c));
printf("%ld",sizeof(s.d));

}
