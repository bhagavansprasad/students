#include"stdio.h"
#include"stdlib.h"

struct node
{
    int data;
    struct node *next;
};
struct node *h=NULL;


int addnode(int val)
{  
    struct node *curr;
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if(h==NULL)
    {
	h=new;
	return 0;
    }
  //  if(h->data>=val)
 //   {
//	new->next=h;
//	h=new;
//	return 0;
 //   }
    for(curr=h;curr->next!=NULL;curr=curr->next)
    {
	if(curr->data<=val&&curr->next->data>=val)
	{
	    new->next=curr->next;
	    curr->next=new;
	    return 0;
	}
    }
    curr->next=new;
    return 0;
}

display()
{
    struct node *curr;
    for(curr=h;curr!=NULL;curr=curr->next)
	printf("%d \t",curr->data);
}

main()
{
    addnode(10);
    addnode(5);
    addnode(15);
    addnode(9);
    addnode(14);
    addnode(12);
    addnode(4);
    addnode(6);
    display();
}
