#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *link;
};
struct node *h=NULL;
main()
{ 
	node_add(25);
	node_add(21);
	node_add(86);
	node_add(20);
	node_add(90);
	node_add(9);
	display();
}
int node_add(int val)
{
	int p;
	struct node *i,*j,*k,*tmp,*new;
	new=malloc(sizeof(struct node));
	new->val=val;
	new->link=NULL;
	if(h==NULL)
	{
		h=new;
		return(0);
	}
	tmp=h;
	while(tmp->link!=NULL)
	{
	tmp=tmp->link;
	}
	tmp->link=new;
	k=h;
	for(i=k;i!=NULL;i=i->link)
	{
		for(j=i->link;j!=NULL;j=j->link)
		{
			if(i->val>j->val)
			{
				p=i->val;
				i->val=j->val;
				j->val=p;
			}
		}
	}
	//return (int *)h;
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
