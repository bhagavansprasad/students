#include <stdio.h>
main()
{
int i,wc=0;
char buff[]="  hi i   am drf derth       ";
for(i=0;buff[i]!='\0';i++)
{
while(buff[i]==' ')
i++;
if(buff[i]!=' ' && buff[i]!='\0')
{
wc=wc+1;
while(buff[i]!=' ' && buff[i]!='\0')
i++;
}
}
printf("%d\n",wc);
}
