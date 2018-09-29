#include<stdio.h>
#include<string.h>
char str[20];
char *astrtoupper(char arr[])
{
 int i=0;
 for(i=0;arr[i];i++)
 {
  str[i]=arr[i]-32;
 }
str[i]='\0';
return str;
}
main()
{
char arr[20]="salmamateen";
char *p;
p=astrtoupper(arr);
printf("%s \n",p);
}
