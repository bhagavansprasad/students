#include<stdio.h>
int add(char *x,...);
main()
{
char x='10';
add(x);
}

add(char *x,...)
{
printf("cursor in called function\n");
return x;
}
