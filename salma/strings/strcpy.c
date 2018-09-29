#include<stdio.h>
char *astrcpy(char str2[],char str1[]);
main()
{
char str1[20]="salma";
char str2[20];
astrcpy(str2,str1);
printf("copied string :%s\n",str2);
}
char *astrcpy(char str2[],char str1[])
{
int i;
for(i=0;str2[i]!='\0';i++)
  str2[i]=str1[i];
  str2[i]='\0';
return str2;
}
