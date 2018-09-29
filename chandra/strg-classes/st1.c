#include<stdio.h>
static int a=10;
//int a=10;
main()
{
//static int a=10;
printf("a:%d\n", a);
fun();
printf("a:%d\n", a);
fun();
}
