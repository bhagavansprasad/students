#include<stdio.h>
//static int a=20;
void fun(void)
{
static int a=20;
printf("a:%d",a);
}
