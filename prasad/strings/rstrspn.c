#include"stdio.h"
int rstrspn(const char *s,const char *charset)
{
int count=0,i,j;
for(i=0;s[i]!='\0';i++)
{
for(j=0;charset[j]!='\0';j++)
{
if(s[i]==charset[j])
{
count++;
break;
}
}
if(charset[j]=='\0')
return count;
}
return count;
}
main()
{
char str1[]="ramprasad";
char str2[]="ram  sd";
int i;
i=rstrspn(str2,str1);
printf("i=%d \n",i);
}
