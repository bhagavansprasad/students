#include<stdio.h>
#include<string.h>
#include<stddef.h>
main()
{
int ret;
char s1[]="auraNETworks";
char s2[]="auranetworks";
ret=strcasecmp(s1,s2);
printf("%d \n",ret);
}

