#include"stdio.h"
#include"stdlib.h"
#define MAX 5
int a[MAX];
int top=-1;
display()
{
    int i;
    if(top==-1)
    {
    printf("STACK IS EMPTY NO ELEMENTS TO DISPLAY\n");
    exit(3);
    }
    else 
       for(i=0;i<=top;i++)
	printf("%d \t",a[i]);
}

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
    int i,rval,value,choice;
    printf("ENTER CHOICE\n");
    printf("1:push()\n");
    printf("2:pop()\n");
    printf("3:display()\n");
    while(1)
    {
    printf("ENTER THE CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
	printf("ENETR THE ELEMENT FOR PUSH:");
	scanf("%d",&value);
	push(value);
	break;
    case 2:
	rval=pop();
	printf("REMOVED ELEMENT FROM STACK :=%d\n",rval);
	if(rval==-1&&top==-1)
	{
	    printf("STACK EMPTY\n");
	}
	break;
    case 3:
	display();
	break;
    default:
	exit(2);
}
}
}
