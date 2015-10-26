#include "stdio.h"
char istoupper(char ch);
main()
{
char ch='H';
int t=0;
t=istoupper(ch);
printf("%c\n",t);
}
char istoupper(char ch)
{
if(ch<='a'&& ch<='z')
{
ch=ch+'a'-'A';
return(ch);
}
return(ch);
}
