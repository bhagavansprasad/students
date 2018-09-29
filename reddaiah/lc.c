#include<stdio.h>
main()
{
int lc=0;
char buff[100]="hi\nreddaiah\nhoe\nare\nyou";
lc=astrlc(buff);
printf("%d",lc);
return 0;
}
int astrlc(char *p)
{
int lc=1,i=0;
for(i=0;p[i]='\0';i++)
{
if(p[i]=='\0')
//printf("%s",p);
lc++;
}
return lc;
}
