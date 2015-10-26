#include"stdio.h"
#include"stdlib.h"

struct node
{
    int data;
    struct node *next;
};
struct node *h=NULL;


int addnode(int pos,int val)
{  
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
    for(i=2,curr=h;curr->next!=NULL;curr=curr->next,i++)
    {
	if(i==pos)
	{
	    new->next=curr->next;
	    curr->next=new;
	    return 0;
	}
    }
    curr->next=new;
    return 0;
}

delete(int val)
{
    struct node *curr,*prev;
    if(h==NULL)
    {
	printf("There are no nodes to delete\r\n");
	return 0;
    }
    if(h->data==val)
    {
	h=h->next;
	return 0;
    }
    for(curr=prev=h;curr!=NULL;prev=curr,curr=curr->next)
    {
	if(curr->data==val)
	{
	    prev->next=curr->next;
	    free(curr);
	    return 0;
	}
    }
    printf("\r\nThere is no element like %d to delete the node from list\r\n",val);
}


display()
{
    struct node *curr;
    curr=h;
 printf("\r\n");
 if(h==NULL)
 {
 printf("no nodes to delete");
 return 0;
 }

 for(curr;curr!=NULL;curr=curr->next)
	printf("%d \t",curr->data);
}

int  main()
{
    addnode(1,10);
    addnode(1,20);
    addnode(2,25);
    addnode(4,30);
    addnode(6,35);
    addnode(4,12);
    printf("node elements before deletion\r\n");
    display();
    delete(20);
    delete(35);
    delete(10);
    delete(12);
    delete(30);
    delete(25);
    display();
	
}
