#include<stdio.h>
main()
{
int a=0x12131415,temp;
short int *sh1,*sh2;
sh1=(short int*)&a;
sh2=sh1+1;
short int sh=*sh2;
printf("%x\n",sh);
char *cp1,*cp2;
cp1=&sh;
cp2=cp1+1;
temp=*cp1;
*cp1=*cp2;
*cp2=temp;
printf("%x\n",*cp1);
printf("%x\n",*cp2);
printf("%x\n",sh);
}

