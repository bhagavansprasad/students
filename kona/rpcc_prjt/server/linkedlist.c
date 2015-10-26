#include <stdio.h>
struct node
{
	int val;
	struct node *link;
};
struct node *h=NULL;
linkedlist()
{ 
	//struct node *p;
	node_add(10);
	node_add(20);
	node_add(30);
	node_add(40);
	node_add(50);
	display();
}
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
int display( int val)
{
	struct node *t;
	for(t=h;t!=NULL;t=t->link )
	{
		printf("%d\n",t->val);
	}
}

int addafter(int val)
{
	struct node *p;
	p=h;
	while(p!=NULL)
	{
		if(p->val==val)
		{
			printf("val is :%d\n",p->link->val);
			return (p->link->val);
		}
		p=p->link;
	}
}

