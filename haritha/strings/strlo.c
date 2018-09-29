#include<stdio.h>
int t;
main()
{
char a='T';
t=tolower(a);
printf("%c",t);
}
int atolower(char ch)
{
ch=ch+32;
return ch;
}
