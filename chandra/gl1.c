#include<stdio.h>
static int a=20;
void my_fun1(void)
{
//static int a=20;
printf("%d\n", a);
a++;
printf("%d\n", a);
}
