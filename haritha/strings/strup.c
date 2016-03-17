#include <stdio.h>
int t;
main()
{
char a='h';
 t=toupper(a);
printf("%c",t);
}
int atoupper(char ch)
{
ch=ch-32;
return ch;
}
