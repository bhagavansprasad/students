#include "stdio.h"
main()
{
char str1[10]="reddy",str2[10]="reddy";
int t=0;
t=astrcmp(str1,str2);
if(t==0)
printf("same\n");
else
printf("not same\n");
}
int astrcmp(char*str1,char*str2)
{
while(*str1==*str2)
{
if(*str1=='\0')
return(0);
str1++;
str2++;
}
return(1);
}
