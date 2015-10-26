#include "stdio.h"
main()
{
char str1[100]="reddy vinay",str2[100]="reeey vinay";
int t,l=6;
t=astrncmp(str1,str2);
if(t==0)
printf("s");
else
printf("n.s");
}
int astrncmp(char*str1,char*str2,int l)
{
int i=0;
while(i<l)
{
if(*str1==*str2)
{
if(*str1=='\0')
return(0);
i++;
*str1++;
*str2++;
}
else
return(1);
}
return(0);
}
