#include<stdio.h>
int i,t;
main()
{
char s1[25]="haritha";
char s2[25]="haaritha";
t=astrncmp(s1,s2,5);
printf("%d",t);
}
int astrncmp(char *s1,char*s2,int n)
{
for(i=0;s1[i]!='\0'&&i<=5;i++)
{
if(s1[i]!=s2[i])
break;
}
if(s1[i]='\0')
return 0;
else 
return 1;
}
