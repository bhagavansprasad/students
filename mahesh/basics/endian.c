#include<stdio.h>
main()
{
int a=0X12345678;
unsigned char *p=(unsigned char *)(&a);
printf("value=%X \n add=%u\n",*p,p);
if(*p==0X12)
printf("big endian");
else
printf("little endian");
}
