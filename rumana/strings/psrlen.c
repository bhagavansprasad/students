#include<stdio.h>
#include<string.h>
unsigned int astrlen(char *name);
main()
{
char name[20];
unsigned int a;
printf("enter name");
gets(name);
a=astrlen(name);
printf("string length is %d\n",a);
}


unsigned int astrlen(char *name)
{
char *p;
p=name;
while(*p!='\0')
p++;
return p-name;
}
