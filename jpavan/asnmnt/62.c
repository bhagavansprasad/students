#include <stdio.h>
main()
{
int a=0x12131415;
int i;
char *ch=&a;
ch=ch+3;
printf("ch1=%x\n",*(ch-0));
printf("ch2=%x\n",*(ch-1));
printf("ch3=%x\n",*(ch-2));
printf("ch4=%x\n",*(ch-3));
for(i=0;i<=3;i++)
{
printf("%x\n",*(ch-i));
}

}
