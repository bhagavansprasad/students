#include"stdio.h"
#include"stdlib.h"

static int count=0;

struct node
{
    int data;
    struct node *next;
};
struct node *h=NULL;


int addnode(int pos,int val)
{  
    count++;
    int flag=1,i;
    struct node *curr;
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if(h==NULL)
    {
	h=new;
	return 0;
    }
    if(flag==pos)
    {
	new->next=h;
	h=new;
	return 0;
    }
    if(count>=pos)
    {
	for(i=2,curr=h;curr!=NULL;curr=curr->next,i++)
	{
	    if(i==pos)
	    {
		if(curr->next!=NULL)
		    new->next=curr->next;
		curr->next=new;
		return 0;
	    }
	}
    }
    printf("unable to insert this node %d becoz position is outof range");
    count--;
    return 0;
}

display()
{
    struct node *curr;
    for(curr=h;curr!=NULL;curr=curr->next)
	printf("%d \t",curr->data);
}

int  main()
{
    addnode(1,10);
    addnode(2,20);
    addnode(3,30);
    addnode(4,40);
    addnode(5,50);
    addnode(2,70);
    addnode(3,90);
    addnode(8,70);
    addnode(9,3);
    display();
}
