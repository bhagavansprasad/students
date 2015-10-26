#include<stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *link;
};
struct node *h=NULL;
int node_add(int val)
{
	struct node *t,*new;
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

struct node *addbefore(struct node *h,int data,int item)
{
	struct node *p,*tmp;
	p=h;
	while(p->link!=NULL)
	{
		if(p->link->val==item)
		{
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->val=data;
			tmp->link=p->link;
			p->link=tmp;
			return (h);
		}
		p=p->link;
     	}
	}
	main()
	{ 
		node_add(20);
		node_add(30);
		node_add(40);
		node_add(50);
		addbefore(h,10,30);
		display();
	}

