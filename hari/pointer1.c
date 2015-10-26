#include<stdio.h>
main()
{
 int a=300,i;
 char * pch;
 pch=&a;
 for(i=0;i<=3;i++)
 { 
 printf("%d\t",*pch);
 pch++;
 
}  
}
