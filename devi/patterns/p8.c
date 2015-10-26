#include <stdio.h>
main()
{
char c='A',ch;
int n=5,i,j,k,sp,count=1,count1,count2=n-1;
sp=n-1;
for(i=0;i<n;i++)
{
ch=c;
if(count<=n)
{
for(j=sp;j>=1;j--)
printf(" ");
for(j=0;j<count;j++)
{
printf("%c",ch);
printf(" ");
ch=ch+1;
}
}
if(count>n)
{
for(k=0;k<count1;k++)
printf(" ");
for(k=1;k<count2;k++)
{
printf("%c",ch);
printf(" ");
ch=ch+1;
}
count2=count2-2;
}
sp=sp-2;
count=count+2;
count1=count-n;
printf("\n");
}
}
