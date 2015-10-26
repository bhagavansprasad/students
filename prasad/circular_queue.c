#include"stdio.h"
#include"stdlib.h"
#define ARRAY_SIZE 5
int arr[ARRAY_SIZE] ,r=-1,f=0,c=0;

display_circular()
{
    int i;
    if(r==-1)
    {
    printf("THERE ARE NO ELEMENTS IN THE CIRCULAR QUE TO DISPLAY");
    return;
    }
    for(i=0;i<c;i++)
	printf("%d \t",arr[i]);
	c--;
}
int delete_atfront()
{
 int rdele;
    if(f>r)
	return -1;
    else 
	rdele=arr[f++];
    return rdele;
}
int insert_atrear(int item)
{
if(c==ARRAY_SIZE)
{
printf("QUEUE IS FULL");
return;
}
else if(r!=ARRAY_SIZE-1)
{
arr[++r]=item;
c++;
return;
}
else if(r==ARRAY_SIZE-1)
{
arr[r-ARRAY_SIZE-1]=item;
c++;
return;
}
}
main()
{
    int i,rval,value,choice;
   // static int c=0;
    printf("ENTER CHOICE\n");
    printf("1:INSERT_ATREAR()\n");
    printf("2:DELETE_FRONT()\n");
    printf("5:DISPLAY()\n");
    while(1)
    {
	printf("ENTER THE CHOICE:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	    printf("ENETR THE ELEMENT FOR INSERTION AT REAREND:");
	    scanf("%d",&value);
	    insert_atrear(value);
	    break;
	case 2:
	    rval=delete_atfront();
	    printf("REMOVED ELEMENT FROM QUEUE AT FRONT END=%d\n",rval);
	    if(rval==-1&&f>r)
	    {
		printf("NO ELEMENTS IN QUEUE TO DELETE\n");
		exit(1);
	    }
	    break;
	case 3:
	    display_circular();
	    break;
	default:
	    exit(2);
	}
    }
}
