#include<stdio.h>
struct s
{
int a;
long e;
};
main()
{
struct s m;
printf("f=%ld\t",sizeof(long));
printf("%ld\t",sizeof(m.a));
printf("%ld\t",sizeof(m.e));
printf("%lu\t",(unsigned long)&m.a);
printf("%lu\t",(unsigned long)&m.e);
printf("%ld",sizeof(struct s));
}
