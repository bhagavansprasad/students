#include<stdio.h>
#include<string.h>
main()
{
int i,j;
char s1[]="siva krishna";
char s2[]="aursa";
i=strspn(s1,s2);
printf("%d",i);
}

