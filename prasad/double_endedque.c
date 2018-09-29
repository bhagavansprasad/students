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
int delete_atrear()
{
 int rdele;
    if(f>r)
	return -1;
    else 
	rdele=arr[r--];
    return rdele;
}
int insert_atfront(int item)
{
if(f==0&&r==-1)
{
arr[++r]=item;
return;
}
else if(f!=0)
{
arr[--f]=item;
return;
}
printf("NO SPACE TO INSERT AT FRONT END");
}
int delete_atfront()
{
    int aele;
    if(f>r)
	return -1;
    else 
	aele=arr[f++];
    return aele;
}
int insert_atrear(int n)
{
    if(r==ARRAY_SIZE-1)
    {
	printf("INSERTION FAILED");
	exit(2);
    }
    r=r+1;
    arr[r]=n;
}
main()
{
    int i,rval,value,choice;
    printf("ENTER CHOICE\n");
    printf("1:INSERT_ATREAR()\n");
    printf("2:DELETE_FRONT()\n");
    printf("3:INSERTION_ATFRONT()\n");
    printf("4:DELETE_ATREAR()\n");
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
	    printf("ENETR THE ELEMENT FOR INSERTION AT FRONT END:");
	    scanf("%d",&value);
	    insert_atfront(value);
	    break;
 	case 4:
	    rval=delete_atrear();
	    printf("REMOVED ELEMENT FROM QUEUE AT REAR END=%d\n",rval);
	    if(rval==-1&&f>r)
	    {
		printf("NO ELEMENTS IN QUEUE TO DELETE\n");
		exit(1);
	    }
            break;
	case 5:
	    display();
	    break;
	default:
	    exit(2);
	}
    }
}
