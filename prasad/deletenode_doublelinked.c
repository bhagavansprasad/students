#include"stdio.h"
#include"stdlib.h"

static int count=0;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *h=NULL;


int addnode(int pos,int val)
{  
    count++;
    int flag=1,i;
    struct node *curr;
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=new->prev=NULL;
    if(h==NULL)
    {
	h=new;
	return 0;
    }
    if(flag==pos)
    {
	curr=h;
	new->next=curr;
	curr->prev=new;
	h=new;
	return 0;
    }
    if(count>=pos)
    {
	for(i=2,curr=h;curr!=NULL;curr=curr->next,i++)
	{
	    if(i==pos)
	    {
		new->prev=curr;
		if(curr->next==NULL)
		{
		    curr->next=new;
		    return 0;
		}
		new->next=curr->next;
		curr->next=new;
		return 0;
	    }
	}
    }
    printf("\n unable to insert this node %d becoz position outof range",new->data);
    count--;
    return 0;
}

delete(int val)
{
    struct node *curr;
    if(h==NULL)
    {
	printf("There is no node to delete");
	return 0;
    }
    if(h->data==val)
    {
	curr=h;
	h=curr->next;
	if(curr->next!=NULL)
	    curr->next->prev=NULL;
	free(curr);
	return 0;
    }
    for(curr=h;curr!=NULL;curr=curr->next)
    {
	if(curr->data==val)
	{
	    curr->prev->next=curr->next;
	    if(curr->next!=NULL)
		curr->next->prev=curr->prev;
	    free(curr);
	    return 0;
	}
    }
    printf("Unable to delete");
}


display()
{
    struct node *curr;
    printf("\r\n");
    for(curr=h;curr!=NULL;curr=curr->next)
	printf("%d \t",curr->data);
}

main()
{

    addnode(1,5);
    addnode(2,10);
    addnode(3,15);
    addnode(4,20);
    addnode(5,25);
    addnode(6,70);
    addnode(7,80);
    printf("elements before deletion\n");
    display();
    delete(5);
    delete(20);

    delete(70);
    display();
}
