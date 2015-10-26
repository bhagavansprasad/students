#include <stdio.h>
#include <string.h>
main()
{
char str[50]="sreenu";
int len;
for(len=strlen(str)-1;len>=0;len--)
printf("%c\n",str[len]);
}
