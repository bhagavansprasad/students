#include<stdio.h>
#include<string.h>
char* astrcpy(char str1[],char str2[]);
main()
{
char str1[20],str2[20];
printf("enter string");
gets(str2);
astrcpy(str1,str2);
printf("string is %s\n",str1);
}
char* astrcpy(char str1[],char str2[])
{
int i=0;
while((str1[i++]=str2[i]));
return str1;
}
