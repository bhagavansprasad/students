#include<stdio.h>
main()
{
int  row=8,val,i,j,k;
for( i=0;i<row;i++)
{
val=1;
for(j=1;j<(row-i);j++)
{
printf(" ");
}
for(k=0;k<=i;k++)
{
printf("  %d",val);
val=val*(i-k)/(k+1);
}
printf("\n\n");
}
printf("\n");
return 0;
}


