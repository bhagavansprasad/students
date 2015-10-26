#include"stdio.h"
#include"stdlib.h"
#define ARRAY_SIZE 5
int arr[ARRAY_SIZE] ,r=-1,f=0;
display()
{
int i;
if(f>r)
{
printf("THERE ARE NO ELEMENTS IN QUEUE TO DISPLAY");
exit(1);
}
for(i=f;i<=r;i++)
printf("%d \t",arr[i]);
}
int insert_atrear(int n)
{
if(r==ARRAY_SIZE-1)
return 0;
r=r+1;
arr[r]=n;
return 1;
}
main()
{
int i,val;
val=insert_atrear(10);
val=insert_atrear(20);
val=insert_atrear(20);
val=insert_atrear(20);
val=insert_atrear(20);
display();
if(val==0)
{
printf("INSERTION FAILED");
exit(1);
}
else 
printf("INSERTION SUCESSES");
}
