#include"stdio.h"
char ptr[10];
char *rstruprtolwr(char *s)
{
int i;
for(i=0;s[i]!='\0';i++)
{
if(s[i]>='A'&&s[i]<='Z')
ptr[i]=s[i]+32;
}
return ptr;
}
main()
{
char str[]="VEERAVENKATARAMPRASADYERRAMSETTI";
char *str1;
str1=rstruprtolwr(str);
printf("str1=%s\n",str1);
}
