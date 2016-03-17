#include <stdio.h>
struct student
{
char a;
short int b;
int c;
};
main()
{
struct student s={'t',10.90};
printf("%p\n",&s.a);
printf("%ld\n",sizeof(s.a));
printf("%p\n",&s.b);
printf("%ld\n",sizeof(s.b));
printf("%p\n",&s.c);
printf("%ld\n",sizeof(s.c));
printf("%ld\n",sizeof(s));
printf("%p\n",&s);
}


