#include<stdio.h>
#include <string.h>
main()
{
char str[]="lucknow";
char *p=str;
p=p+3;
p[3]='t';
printf("%s\n",str);
printf("%s\n",p);
}
