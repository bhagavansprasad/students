#include<stdio.h>
struct s
{
short a;
char e;
};
main()
{
struct s m;
printf("f=%ld\t",sizeof(short));
printf("%ld\t",sizeof(m.a));
printf("%ld\t",sizeof(m.e));
printf("%lu\t",(unsigned long)&m.a);
printf("%lu\t",(unsigned long)&m.e);
printf("%ld",sizeof(struct s));
}
