#include<stdio.h>
#include<string.h>
char str[20];
char* astrtoggle(char arr[])
{
int i=0;
for(i=0;arr[i]!='\0';i++)
{
if(arr[i]>=65&&arr[i]<=91)
  str[i]=arr[i]+32;
else if(arr[i]>=97&&arr[i]<=123)
 str[i]=arr[i]-32;
 else 
 str[i]=arr[i];
}
str[i]='\0';
return str;
}
main()
{
char arr[]="Aura Networks";
char *p;
p=astrtoggle(arr);
printf("%s\n",p);
}
