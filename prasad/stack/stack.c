#include"stdio.h"
#include"stdlib.h"
#define ASIZE 5
int top=-1;
int a[ASIZE];
int push(int item)
{
if(top==ASIZE-1)
{
printf("STACK OVER FLOW");
return 0;
}
a[++top]=item;
}
int pop()
{
int m;
if(top==-1)
{
printf("THE STACK IS EMPTY");
exit(1);
}
m=a[top--];
return m;
}
main()
{
int i,n;
push(10);
push(20);
push(30);
push(40);
push(50);
for(i=0;i<ASIZE;i++)
printf("%d ",a[i]);
for(i=0;i<5;i++){
n=pop();
printf("the array element removed=%d \n",n);
}
push(60);
push(70);
printf("THE ARRAY ELEMENTS AFTER REMOVING\n");
for(i=0;i<=top;i++)
printf("%d ",a[i]);
}
