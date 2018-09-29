#include <stdio.h>
main()
{
int i,j=0;
char str1[]=",,,,,,thghhh,,,,,,,";
//char str2[100];
char ch=',';
char *q;
q=&str1[0];
printf("\n%s",str1);
stringseperator(q,ch);
printf("%s",str1);
}
char* stringseperator(char **s,char c)
{
int i,j;
char str2[100];
for(i=0;s[i]!='\0';i++)
{
if(s[i]!=c)
{
str2[j]=s[i];
j++;
}
}
str2[j]='\0';
printf("\n%s\n",str2);
}
