#include "stdio.h"
#include "stdlib.h"
struct student
{
	int no;
	struct student *next;
};
struct student *h=NULL;
int add_node(int value);
int add_at_begining(int value);
int add_at_posi(int value,int posi);
void display();
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_at_begining(20);
	add_at_posi(70,4);
	display();
}
int add_node(int value)
{
	struct student *new,*t;
	new=malloc(sizeof(struct student));
	{
		new->no=value;
		new->next=NULL;
	}
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	t=h;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new;
	return 0;
}
void display()
{
	struct student *t=h;
	while(t!=NULL)
	{
		printf("%d\n",t->no);
		t=t->next;
	}
}
int add_at_begining(int value)
{
	struct student *new;
	new=malloc(sizeof(struct student));
		new->no=value;
		new->next=h;
		h=new;
}
int add_at_posi(int value,int posi)
{
	struct student *new,*t;
	int i;
	t=h;
	for(i=1;i<posi-1 && t!=NULL;i++)
	{
		t=t->next;
	}
	if(t==NULL)
	{
		printf("there are no nodes:");
	}
	else
	{
		new=malloc(sizeof(struct student));
		new->no=value;
	}
	if(posi==1)
	{
		new->next=h;
		h=new;
	}
	else
	{
		new->next=t->next;
		t->next=new;
	}
}
