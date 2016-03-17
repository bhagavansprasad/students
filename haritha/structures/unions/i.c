#include <stdio.h>
#include <string.h>
union student
{
char  b;
short int a;
char age;
//	int marks;
};
main()
{
union student s;
{
	//strcpy(s.name,"thanu");
	s.b='1';
	printf("%p\n",&s.b);
	printf("%ld\n",sizeof(s.b));
	s.a=0;
	printf("%p\n",&s.a);
	printf("%ld\n",sizeof(s.a));
	s.age='0';
	printf("%p\n",&s.age);
	printf("%ld\n",sizeof(s.age));	
	//s.marks=10;
	//printf("%p\n",&s.marks);
	//printf("%ld\n",sizeof(s.marks));
printf("%ld\n",sizeof(s));
printf("%p\n",&s);
}
}
