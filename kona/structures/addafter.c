#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *link;
};
struct node *new;
struct node *start=NULL;
int node_add(int val)
{
	struct node *t;
	new=malloc(sizeof(struct node));
	new->val=val;
	new->link=NULL;
	if(start==NULL)
	{
		start=new;
		return(0);
	}
	for(t=start;t->link!=NULL;t=t->link);
	t->link=new;
}
  display()
{
	struct node *t;
	for(t=start;t!=NULL; t=t -> link)
	{
		printf("%d\n",t->val);
	}
}
struct node* add_after(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->val==item)
		{
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->val=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
}

//struct node *addatbegin(struct node *,int);
main()
{ 
	//struct node *start;
	//addatbegin(start,10);
	node_add(20);
	node_add(30);
	node_add(40);
	node_add(50);
	add_after(start,35,30);
	display();
}
