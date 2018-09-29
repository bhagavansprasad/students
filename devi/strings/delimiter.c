#include <stdio.h>
main()
{
int i,j=0;
char str1[]=",,,,,,thghhh,,,,,,,";
char str2[100];
char ch=',';
printf("\n%s",str1);
for(i=0;str1[i]!='\0';i++)
{
if(str1[i]!=ch)
{
str2[j]=str1[i];
j++;
}
}
str2[j]='\0';
printf("\n%s\n",str2);
}
