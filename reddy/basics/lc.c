#include "stdio.h"
#include  "fcntl.h"
main()
{
char buff[100]="reddy vinay\n"
				"dastha giri\n"
				"msn njwnx  jsnjkaxn\0";
int lc=0;
lc=alinecount(buff);
printf("the line count is %d\r\n",lc);
return(0);
}
int alinecount(char *p)
{
int i=0,lc=1;
for(i=0;p[i]!='\0';i++)
{
if(p[i]=='\n')
lc=lc+1;
}
return(lc);
}
