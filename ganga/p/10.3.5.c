#include<stdio.h>
struct s
{
char a;
char b;
char c;
char d;
char f;
int e;
};
main()
{
struct s m;
printf("%ld\t",sizeof(m.a));
printf("%ld\t",sizeof(m.b));
printf("%ld\t", sizeof(m.c));
printf("%ld\t", sizeof(m.d));
printf("%ld\t",sizeof(m.e));
printf("%lu\t",(unsigned long)&m.a);
printf("%lu\t",(unsigned long)&m.b);
printf("%lu\t",(unsigned long)&m.c);
printf("%lu\t",(unsigned long)&m.d);
printf("%lu\t",(unsigned long)&m.f);
printf("%lu\t",(unsigned long)&m.e);
printf("c=%ld\n",sizeof(struct s));
}

