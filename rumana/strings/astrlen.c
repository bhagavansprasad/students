#include<stdio.h>
#include<string.h>
unsigned int astrlen(name[]);
main()
{
int a;
char name[20];
printf("enter name");
gets(name);
a=astrlen(name);
printf("string length is %d\n",a);
}

unsigned int astrlen(name[])
{
int i=0;
while(name[i]!='\0')
i++;
return i;
}
