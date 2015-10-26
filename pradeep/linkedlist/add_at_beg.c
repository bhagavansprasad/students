#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int no;
	struct node *next;
};
struct node *h=NULL;
int main()
{
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_node(60);
	dump_list();
	add_node_beg(10);
	dump_list();
}
int dump_list()
{
struct node *t;

	for(t=h;t!=NULL;t=t->next)
	{
		printf("%10d\n",t->no);
	}
	printf("---->*******<----\n");
}
int add_node(int value)
{
	struct node *new,*t;
	new = malloc(sizeof(struct node));
	new->no = value;
	new->next = NULL;
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	for(t=h;t->next!=NULL;t=t->next);
	t->next=new;
	return 0;
}
int add_node_beg(int value)
{
	struct node *curr,*new;
	new = malloc(sizeof(struct node));
	new->no = value;
	new->next = NULL;
	curr = new;
	if(curr->no==value)
	{
		curr->next = h;
		h = curr;
		return 0;
	}
}
