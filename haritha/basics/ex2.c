#include <stdio.h>
main()
{
char ch[100]="aura net";
display (ch);
}
int display(char *p)
{
int i;
for(i=0;*p!='\0';p++,i++)
{
printf("%c",p[i]);
}
}
