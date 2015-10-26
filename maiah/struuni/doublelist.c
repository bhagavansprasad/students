#include <stdio.h>
#include <stdlib.h>
struct node
{
	int no;
	struct node *next;
	struct node *prev;
};
struct node *h=NULL;
int add_node(int value);
int add_at_position(int value,int position);
void display();
int add_at_bigin(int value);
int add_at_end(int value);
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_node(60);
	add_node(70);
	add_at_position(80,6);
	add_at_bigin(25);
	add_at_end(90);
	display();
}
int add_node(int value)
{
	struct node *new,*t;
	new=malloc(sizeof(struct node));
	new->no=value;
	new->prev=NULL;
	new->next=NULL;
	
	//new->prev=NULL;
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	t=h;
	while(t->next!=NULL)
	{
		t=t->next;
		//new->prev=t;
	}
	t->next=new;
	new->prev=t;
	return 0;
}
void display(void)
{
	struct node *t=h;
	while(t!=NULL)
	{
		printf("%d\n",t->no);
		t=t->next;
	}
}
int add_at_position(int value,int position)
{
	int c=0;
	struct node *new,*t;
	new=malloc(sizeof(struct node));
	new->next=new->prev=NULL;
	new->no=value;
	for(t=h;t!=NULL;t=t->next)
	{
		c++;
		if(c==position)
			break;
	}
	new->prev=t;
	new->next=t->next;
	t->next=new;
	new->next->prev=new;
	return 0;
}
int add_at_bigin(int value)
{
	struct node *new;
	new=malloc(sizeof(struct node));
	new->no=25;
	new->prev=NULL;
	new->next=h;
	h=new;
	new->next->prev=new;
	return 0;
}
int add_at_end(int value)
{
	struct node *new,*t;
	new=malloc(sizeof(struct node));
	new->no=90;
	t=h;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new;
	new->prev=t;
	return 0;
}
