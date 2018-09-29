#include<stdio.h>
struct size
{
char a;
int b;
};
struct s
{
int a;
int b;
};
main()
{
struct size me;
struct s m;
printf("%ld\t",sizeof(me.a));
printf("%ld\t", sizeof(me.b));
printf("%lu\t",(unsigned long)&me.a);
printf("%lu\t",(unsigned long)&me.b);
printf("c=%ld\n",sizeof(struct size));
printf("%ld\t",sizeof(m.a));
printf("%ld\t", sizeof(m.b));
printf("%lu\t",(unsigned long)&m.a);
printf("%lu\t",(unsigned long)&m.b);
printf("c=%ld\t",sizeof(struct size));
}



