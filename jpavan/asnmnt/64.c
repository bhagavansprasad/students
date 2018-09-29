#include<stdio.h>
main()
{
int a=0x12131415,ch1,ch2,ch3,ch4,t;
char *ch=&a;
ch=ch+3;
ch1=*(ch-0);
ch2=*(ch-1);
ch3=*(ch-2);
ch4=*(ch-3);
printf("%x%x%x%x\n",ch1,ch2,ch3,ch4);
swap(&ch1,&ch4);
swap(&ch2,&ch3);
/*ch1;
ch1=ch4;
ch4=t;
t=ch2;
ch2=ch3;
ch3=t;*/
printf("%x%x%x%x\n",ch1,ch2,ch3,ch4);
}
int swap(int *s,int *b)
{
int t;
t=*s;
*s=*b;
*b=t;
}
