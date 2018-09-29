#include<stdio.h>
int astrcmp(char*,char*);
main()
{
char str1[]="Salma";
char str2[]="salma";
int t=astrcmp(str1,str2);
if(t==0)
printf("equal\n");
else if(t>0)
printf("string1 is big\n");
else
printf("string2 is big\n");
}
int astrcmp(char *p,char *q)
{
 int i=0;
 while(*p == *q)
 {
   if(*p=='\0')
   return 0;
  p++;
  q++;
 }
 return ((*p)-(*q));
}
