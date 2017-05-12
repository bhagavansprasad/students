#include<stdio.h>
struct s
{
int i;
char a;
int b;
char c;
};
main()
{
struct s m;
printf("%ld\t",sizeof(m.i));
printf("%ld\t",sizeof(m.a));
printf("%ld\t", sizeof(m.b));
printf("%ld\t", sizeof(m.c));
printf("%lu\t",(unsigned long)&m.i);
printf("%lu\t",(unsigned long)&m.a);
printf("%lu\t",(unsigned long)&m.b);
printf("%lu\t",(unsigned long)&m.c);
printf("c=%ld\n",sizeof(struct s));
}


