#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *link;
};
struct node *h=NULL;
int node_add(int );
void detectloop(struct node *);
void circular(struct node *);
main()
{ 
	node_add(10);
	node_add(20);
	node_add(30);
	node_add(40);
	node_add(50);
	//h->link->link->link->link->link=h;
	detectloop(h);
	middle(h);
	display();
}
int node_add(int val)
{
	struct node *t,*new;
	new=malloc(sizeof(struct node));
	new->val=val;
	if(h==NULL)
	{
		h=new;
		return(0);
	}
	for(t=h;t->link!=NULL;t=t->link);
	t->link=new;
}
int display( int val)
{
	struct node *t;
	for(t=h;t!=NULL;t=t->link )
	{
		printf("%d\n",t->val);
	}
}
void detectloop(struct node *h)
{
	struct node *first,*second;
	first=second=h;
	while(first && second && second->link)
	{
		first=first->link;
		second=second->link->link;
	}
	if(first==second)
	{
		printf("loop will be found\n");
	}
	else
	{
		printf("loop will not found\n");
	}
}
void middle(struct node *h)
{
	struct node *slow,*fast;
	slow=fast=h;
	if(h!=NULL)
	{
		while(slow!=NULL && fast->link!=NULL)
		{
			slow=slow->link;
			fast=fast->link->link;
		}
		printf("middle node is %d\n",slow->val);
	}
}
void circular(struct node *h)
{
	struct node *t=h;
	if(h!=NULL)
	{
		do
		{
			printf("%d\n",t->val);
			t=t->link;
		}
		while(t!=NULL);
	}
}
