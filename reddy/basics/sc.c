#include "stdio.h"
main()
{
char str1[10]="reddy",str2[10]="reDDY";
int t,n=2;
t= astrncmp(str1,str2);
if(t==0)
printf("same\n");
else
printf("not same\n");
}
int astrncmp(char *str1,char *str2,int n)
{
while(*str1==*str2)
{
int n=2;
if(*str2==n)
{
return(0);
}
str1++;
str2++;
}
return(1);
}
