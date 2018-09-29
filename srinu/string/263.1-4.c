#include<stdio.h>
#include <string.h>
main()
{
char str1[]="paru1";
char str2[10];;
strcpy(str2,str1);
if(str1==str2)
printf("same\n");
else
printf("different\n");
}
