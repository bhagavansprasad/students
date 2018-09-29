#include<stdio.h>
#include <stdlib.h>
#include<string.h>
main()
{
char str1[]="Aura";
char size=sizeof(str1);
//printf("-->%d",sizeof(str1));
char str2[size];
strrev(str1);
}
void strrev(char *s1)
{
char str2[5],*s2;
s2=&str2;

//printf("started\n");
//printf("%s\n",s1);
int len=strlen(s1);
while(*s1!='\0')
{
s1=(s1+len);
*s2=*s1;
len--;
s2++;
}
*s2='\0';
printf("%s",str2);
}
