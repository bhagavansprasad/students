#include "stdio.h"
char istolower(char ch);
main()
{
char ch='D';
int t=0;
t=istolower(ch);
printf("%c\n",t);
}
char istolower(char ch)
{
if(ch>='A'&& ch<='Z')
{
ch=ch+'a'-'A';
return(ch);
}
return(ch);
}
