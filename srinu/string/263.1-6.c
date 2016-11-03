#include<stdio.h>
#include <string.h>
main()
{
char str1[]="paru";
char str2[]={'p','a','r','u'};
if(strcmp(str1,str2)==0)
printf("same\n");
else
printf("different\n");
}
