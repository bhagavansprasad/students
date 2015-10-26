#include<stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *link;
};
struct node *new;
struct node *h=NULL;
int addatpos(int val,int pos);
main()
{ 
	node_add(20);
	node_add(30);
	node_add(40);
	node_add(50);
	addatpos(10,4);
	display(h);
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
int display()
{
	struct node *t;
	for(t=h;t!=NULL; )
	{
		printf("%d\n",t->val);
		t=t -> link;
	}
}
int addatpos(int data,int pos)
{
	struct node *tmp,*p;
	int i;
	p=h;
	for(i=1;i<pos-1 && p!=NULL;i++)
	p=p->link;
	if(p==NULL)
	printf("less elements %d",pos);
	else
	{
		tmp=malloc(sizeof(struct node));
		tmp->val=data;
		if(pos==1)
		{
			tmp->link=h;
			h=tmp;
		}
		else
		{
			tmp->link=p->link;
			p->link=tmp;
		}
	}
	return h;
}
