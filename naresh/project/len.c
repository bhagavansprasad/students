#include<stdio.h>
#include <fcntl.h>
main()
{
char buff[100]="hi hello how are ";
int ln;
ln=astrln(buff);
printf("length of string = %d\n",ln);
}
int astrln(char *p)
{
int i=0,ln=0;
for(i=0;p[i]!='\0';i++);
return i;
}
