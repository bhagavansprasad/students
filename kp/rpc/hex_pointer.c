#include<stdio.h>
main()
{
int a=0x12131415;
char *pch=&a;
short int *pa=&a;
printf("%x,%x,%x,%x\n",*pch,*(pch+1),*(pch+2),*(pch+3));
printf("%x,%x\n",*(pa+1),*pa);
printf("%x\n",a);
printf("%x%x%x%x\n",*pch,*(pch+1),*(pch+2),*(pch+3));
}

