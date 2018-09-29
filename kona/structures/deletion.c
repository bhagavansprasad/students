#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *link;
};
struct node *h=NULL;
int  deletion_after(int val);
main()
{ 
	node_add(20);
	node_add(30);
	node_add(40);
	node_add(50);
	deletion_after(30);
	display();
}
int node_add(int val)
{
	struct node *new,*t;
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

int deletion_after(int val)
{
	struct node *p,*tmp;
	/*deletion of first node*/
/*	if(h->val==val)
	{
		tmp=h;
		h=h->link;
		free(tmp);
		return h;
	}*/
	
/* deletion of middle (or) last node */	
	p=h;
	while(p->link!=NULL)
	{
		if(p->link->val==val)
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return h;
		}
	p=p->link;
	}
}
