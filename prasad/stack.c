#include"stdio.h"
#include"stdlib.h"
#define MAX 5
int a[MAX];
int top=-1;
int pop()
{
int aele;
if(top==-1)
{
return -1;
}
aele=a[top];
top--;
return aele;
}
void push(int ele)
{
if(top==MAX-1)
{
printf("STACK FULL");
exit(1);
}
top++;
a[top]=ele;
}
main()
{
int i,rval;
push(10);
push(20);
push(-1);
push(50);
push(60);
for(i=0;i<MAX;i++)
printf("%d \t",a[i]);
rval=pop();
rval=pop();
rval=pop();
rval=pop();
rval=pop();

rval=pop();
for(i=0;i<=top;i++)
printf("%d \t",a[i]);
if(rval==-1&&top==-1)
{
printf("STACK EMPTY");
}
}
