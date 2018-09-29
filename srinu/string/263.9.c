#include<stdio.h>
#include <string.h>
main()
{
char str[]="painstaking";
char *p=str+5;
printf("%c\t",*p);
printf("%s\n",p);
}
