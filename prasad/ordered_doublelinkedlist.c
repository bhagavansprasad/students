#include"stdio.h"
#include"stdlib.h"

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *h=NULL;

int addnode(int val)
{  
    struct node *curr;
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->prev=new->next=NULL;
    if(h==NULL)
    {
	h=new;
	return 0;
    }
    if(h->data>=val)
    {
	new->next=h;
	h->prev=new;
	h=new;
	return 0;
    }
    for(curr=h;curr->next!=NULL;curr=curr->next)
    {
	if(curr->data<=val&&curr->next->data>=val)
	{
	    new->next=curr->next;
	    new->prev=curr;
	    curr->next=new;
	    return 0;
	}
    }
    new->prev=curr;
    curr->next=new;

    return 0;
}

display()
{   
    printf("\r\n");  
    struct node *curr;
    for(curr=h;curr!=NULL;curr=curr->next)
	printf("%d \t",curr->data);
    printf("\r\n");

}

main()
{
    addnode(10);
    addnode(4);
    addnode(5);
    addnode(15);
    addnode(9);
    addnode(11);
    addnode(20);
    addnode(1);
    addnode(6);
    addnode(12);
    display();
}
