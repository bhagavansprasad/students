#include"stdio.h"
int rstrcspn(const char *s,const char *charset)
{
int c=0,i,j;
for(i=0;s[i]!='\0';i++)
{
for(j=0;charset[j]!='\0';j++)
{
if(s[i]==charset[j])
return c;
}
c++;
}
return c;
}
main()
{
char str1[]="rhhhhhhamhhhh";
char str2[]="uram";
int i;
i=rstrcspn(str1,str2);
printf("i=%d \n",i);
}

