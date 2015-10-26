#include<stdio.h>
#include<string.h>
char *astrrchr(char *p,int n)
{
 while(*p!='\0')
 p++;
 while(*p!=n)
 p--;
 return p;
}
main()
{
char str[20]="salmamateen";
char *ptr=astrrchr(str,'m');
printf("the string is %s\n",ptr);
}
