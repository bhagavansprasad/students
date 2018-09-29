#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
	int val;
struct node *link;
};
struct node *start=NULL;
main()
{ 
	node_add(10);
	node_add(20);
	node_add(30);
	node_add(40);
	node_add(50);
	display();
	printf("\n");
	delete_node(start);
	delete_node(start->link);
	delete_node(start->link);
	display();
}
int node_add(int val)
{
	struct node *p,*tmp = start;
	struct node *new;
	new=malloc(sizeof(struct node));
	new->link=NULL;
	if(start==NULL)
	{
		start=new;
		start->prev=NULL;
		start->val=val;
		start->link=NULL;
		return 0;
	}
	while(tmp->link!=NULL)
	{
	tmp = tmp->link;
	}
	tmp->link=new;
	p=tmp->link;
	p->prev=tmp;
	p->val=val;
	p->link=NULL;
	return 0;
}
int display( int val)
{
	struct node *t;
	for(t=start;t!=NULL; )
	{
		printf("%d\n",t->val);
		t=t -> link;
	}
}
void delete_node(struct node *p)
{
	if(start==p)
	{
		start=p->link;
	}
	if(p->link!=NULL)
	p->link->prev=p->prev;
	if(p->prev!=NULL)
	p->prev->link=p->link;
	free(p);

}
