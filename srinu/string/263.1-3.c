#include<stdio.h>
#include <string.h>
main()
{
char str1[15]="good";
char char str2[]="evening";
strcpy(str1+strlen(str1),str2);
printf("%s\n",str1);
}
