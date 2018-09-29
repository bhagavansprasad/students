#include<stdio.h>
#include<string.h>

 char astr1[50];
char *astrlower(char arr[])
{
 //char astr1[50];
 int i;
 for(i=0 ;arr[i]!='\0';i++)
 {
 astr1[i]=arr[i]+32;
 }
 astr1[i]='\0';
 return astr1;
}
main()
{
char arr[]="SALMAMATEEN";
char *p;
p=astrlower(arr);
printf("%s\n",p);
}
