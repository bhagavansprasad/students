#include<stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *link;
};
struct node *new;
struct node *h=NULL;
struct node *reverse(struct node *h);
main()
{ 
	node_add(20);
	node_add(30);
	node_add(40);
	node_add(50);
	display(h);
	printf("\n");
	struct node *rev = reverse(h);
	display(rev);
}
int node_add(int val)
{
	struct node *t=h;
	new=malloc(sizeof(struct node));
	new->val=val;
	new->link=NULL;
	if(h==NULL)
	{
		h=new;
		return(0);
	}
	for(t=h;t->link!=NULL;t=t->link);
	t->link=new;
	}
}
int display(struct node *h)
{
	struct node *t;
	for(t=h;t!=NULL; )
	{
		printf("%d\n",t->val);
		t=t -> link;
	}
}

struct node *reverse(struct node *h)
{
	struct node *prev,*ptr,*next;
	prev=NULL;
	ptr=h;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	h=prev;
	return h;

}

