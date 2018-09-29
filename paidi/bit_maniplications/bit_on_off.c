#include<stdio.h>
/*
main()
{
 int i,a=3,p,mask=0;
 for(i=0;i<32;i++)
  {
    mask=1<<i;
    p=a&mask;
    if(p==0)
     printf("off-->= %d\n",p);
     else
     printf("on--->= %d\n",p);
  }
}*/


main()
{
int i,mask,p,num=20;
for(i=31;i>=0;i--)
 {
  mask = num & (1<<i);
  (mask==0)? printf("0 "): printf("1 ");
 }
 printf("\n");
}

