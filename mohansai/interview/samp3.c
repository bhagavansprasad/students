#include "stdio.h"
main()
{
char *p1="mohansai";
char *p2;

p1=p2;
p2=(char*)malloc(20);

while(*p2++=*p1++);

printf("%s",p2);
}


