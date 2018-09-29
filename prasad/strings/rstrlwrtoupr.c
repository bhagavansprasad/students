#include"stdio.h"
char ptr[10];
char *rstrlwrtoupr(char *s)
{
int i;
for(i=0;s[i]!='\0';i++)
{
if(s[i]>='a'&&s[i]<='z')
ptr[i]=s[i]-32;
}
return ptr;
}
main()
{
char str[]="veeravenkataramprasadyerramsetti";
char *str1;
str1=rstrlwrtoupr(str);
printf("str1=%s\n",str1);
}
