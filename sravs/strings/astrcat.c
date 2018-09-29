#include<stdio.h>
#include<string.h>
char* astrcat(char str1[],char str5[])
{
	int i,j=0;
for(i=0;str1[i]!='\0';i++);
while(str5[j]!='\0')
{
str1[i]=str5[j];
i++;
j++;
}
str1[i]='\0';
return str1;
}
