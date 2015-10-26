#include"stdio.h"
main()
{
int i,j;
int a[]={1,2,8,4,2,1,3,5,1};
for(i=0;i<9;i++)
{
for(j=i+1;j<9;j++)
{
if(a[i]==a[j])
{
a[j]=0;
}
}
}
for(i=0;i<9;i++)
{
printf("a[%d]=%d \n",i,a[i]);
}

}

