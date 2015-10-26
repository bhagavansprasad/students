#include<stdio.h>
main()
{
char t;
char s1[40]="hi naresh how are you";
char s2[40];
t=astrcpy(s2,s1);
printf("%s\n",s2);
return 0;
}
int astrcpy(char *s2,char *s1)
{
int i=0,n=10,t;
for(i=0;i<=n;i++)
{
s2[i]=s1[i];
}
return t;
}
