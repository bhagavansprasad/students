#include<stdio.h>
extern int a;
void fun1(void)
{
//extern int a;
printf("a:%d\n", a);
a++;
}
