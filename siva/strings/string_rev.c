#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
char s1[]="siva krishna";
char s2[30];
int n=strlen(s1);
int i;
s2[n]='\0';
for(i=0;i<=n;i++)
{
s2[n-1-i]=s1[i];
}
printf("%s\n",s1);
printf("%s\n",s2);
}
