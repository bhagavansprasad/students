#include "stdio.h"
#include "stdlib.h"
struct student
{
	int no;
	struct student *next;
};
struct student *h=NULL;
int add_node(int val);
int add_atbeg(int n);
void display(void);
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_atbeg(25);
	display();
}
int add_node(int val)
{
	struct student *new,*t;
	new=malloc(sizeof(struct student));
	new->no=val;
	new->next=NULL;
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
void display(void)
{
	struct student *t=h;
	while(t!=NULL)
	{
		printf("%d\n",t->no);
		t=t->next;
	}
}
int add_atbeg(int n)
{
	struct student *new;
	new=malloc(sizeof(struct student));
	new->no=n;
	new->next=h;
	h=new;
	return 0;
}
