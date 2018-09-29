#include<string.h>
#include<stdio.h>
main()
{
char str1[20]="hello";
char str2[20]="world";
printf("%s",str2);
printf("%s\n",strcpy(str2,strcat(str1,str2)));
}
