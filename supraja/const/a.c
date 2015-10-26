#include <stdio.h>
main()
{
int a=10;
char *p;
p=(char *)&a;
printf("%d\n",sizeof(++p));
}
