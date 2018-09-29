#include <stdio.h>
#include <string.h>
main()
{
char str1[20]="aura networks";
char str2[10]="ura";
char *ret;
ret=strstr(str1,str2);
printf("%p\n",ret);
printf("%s\n",ret);
}
