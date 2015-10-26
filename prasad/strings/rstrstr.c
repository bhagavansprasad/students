#include"stdio.h"
#include"string.h"
char *rstrstr(const char *s,const char *n)
{
char *ch=NULL;
int i,j;
for(i=0;s[i]!='\0';i++)
{
if(s[i]==n[0])
{
ch=s+i;
for(j=0;n[j]!='\0';j++)
{
if(s[i]!=n[j])
break;
i++;
}
if(n[j]=='\0')
return ch;
i--;
}
}
return ch;
}
main()
{
char str1[]="ram vvvvr prasad";
char str2[]="vvr";
char *chr,*cht;
chr=rstrstr(str1,str2);
cht=strstr(str1,str2);
if(chr!=NULL)
{
printf("chr=%s\r\n",chr);
}
else
printf("chr==%s\r\n",chr);
}
