#include<stdio.h>
main()
{
char str[]="SalmaMateen";
int t=astrlen(str);
printf(" length is :%d\n",t);
}
int astrlen(char *p)
{
char *q=p;
while(*q!='\0')
 q++;
return q-p;
}
