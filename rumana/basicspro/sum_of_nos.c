#include<stdio.h>
main()
{
int i,sum=1,add=0;
for(i=0;i<5;i++)
{
sum=sum+i;
add=add+sum;
}
printf("sum is %d\n",add);
}
