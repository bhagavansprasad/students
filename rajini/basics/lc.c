#include<stdio.h>
main()
{
int lc=0,len=0,lc=0;
char buff[100]="rajini\nkanth\nreddy";
len=astrlen(buff);
printf("%d",len);
lc=astrlc(buff);
printf("%5d\n",lc);
wc=astrwc(buff);
printf("%d",wc);
return 0;
}
int astrlen(char *p)
{
int i=0,len=0;
for(i=0;p[i]!='\0';i++);
return i;
}
int astrlc(char *p)
{
int lc=1,i=0;
for(i=0;p[i]!='\0';i++)
{
if(p[i]=='\n')
lc++;
}
return lc;
}
int astrwc(char *p)
{
int i=0,wc=1;
for(i=0;p[i]!='\0';i++)
{
if(p[i]==" ")
wc=wc+1;
}
return wc;
}
