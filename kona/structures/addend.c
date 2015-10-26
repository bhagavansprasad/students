#include<stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *link;
};
struct node *new;
struct node *h=NULL;
int node_add(int val)
{
	struct node *t;
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
display()
{
	struct node *t;
	for(t=h;t!=NULL; t=t -> link)
	{
		printf("%d\n",t->val);
	}
}
struct node* addatend(struct node *h,int data)
{
	struct node *p,*tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->val=data;
	p=h;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return h;
}
main()
{ 
	node_add(20);
	node_add(30);
	node_add(40);
	node_add(50);
	addatend(h,60);
	display();
}

