#include <stdio.h>
main()
{
int a=10;
int b=20;
int c=30;
printf("a:%u\n", &a);
printf("b:%u\n", &b);
printf("c:%u\n", &c);
fun1();
}
void fun1(void)
{
int d=40;
int e=50;
printf("d:%u\n", &d);
printf("e:%u\n", &e);
fun2();
}
void fun2(void)
{
int f=60;
int g=70;
printf("f:%u\n", &f);
printf("g:%u\n", &g);
}
