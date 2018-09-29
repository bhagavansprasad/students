#include"stdio.h"
#include"stdlib.h"
#define MAX 10
int a[MAX]={5,3,8,2,9},i,c=4;
int insert(int pos,int ele)
{
c++;
if(c==MAX-1)
{
printf("ARRRAY OUT OF BOUNDARY");
return;
}
  for(i=c-1;i>=0;i--)
  {
    if(i==pos)
    { 
      a[i+1]=a[i];
      a[pos]=ele;
      return;
    }
    a[i+1]=a[i];
  }
}
main()
{
  insert(2,10);
 insert(3,20);
  insert(4,30);
 // insert(5,90);

  //insert(0,1);
  //insert(6,6);
  //insert(7,89);
  //insert(5,90);
  //insert(5,90);
  //insert(5,90);
  for(i=0;i<=c;i++)
    printf("%d ",a[i]);
}
