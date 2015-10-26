#include <stdio.h>
main()
{
int a=0x12131415,i;
char *ch;
ch=(char*)&a;
ch=ch+3;
for(i=0;i<4;i++)
{
printf("%x",*ch);
ch--;
}
}

