#include<stdio.h>
main()
{
 int i;
char a[20];
printf("%d\n",a);
for(i=0;i<=19;i++)
 
  *(a+i)=65;
 
  //*(a+i)='\0';
 printf("%s\n",a);
 
}
