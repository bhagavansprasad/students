#include<stdio.h>
main()
{
int a=300;
int *p=&a;
short int *sp=&a;
char *pc=&a;
printf("%d\n",*p);
printf("%d\n",*sp);
printf("%d\n",*pc);
}
