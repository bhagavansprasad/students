#include <stdio.h>
char atolower(char c)
{
int  d=c+32;
return (char)d;
}
main()
{
char c='A';
char d=atolower(c);
printf("%c \n",d);
}
