#include<stdio.h>
main()
{
int wc=0;
char buff1[100]="rajini  kanth";
wc=awc(buff1);
printf("%d",wc);
return 0;
}
int awc(char *p)
{
int i=0,wc=1;
for(i=0;p[i]!='\0';i++)
{
if(p[i]==' ')
wc=wc+1;
}
return wc;
}
