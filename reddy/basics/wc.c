#include"stdio.h"
#include"fcntl.h"
main()
{
char buff[100]="reddy vinay";
int wc=0;
wc=awordcount(buff);
printf("word count is %d",wc);
return(0);
}
int awordcount(char *p)
{
int i=0,wc=1;
for(i=0;p[i]!='\0';i++)
{
if(p[i]=='-')
wc=wc+1;
}
return(wc);
}
