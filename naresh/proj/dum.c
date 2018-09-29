#include "stdio.h"
#include "stdlib.h"
struct stud
{
	int no;
	struct stud *next;
};
struct stud *h=NULL;
void display();
int add_node(int val);
int del_by_val(int val);
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	del_by_val(30);
	
	display();
}
void display()
{
	struct stud *t=h;
	while(t!=NULL)
	{
		printf("%d\n",t->no);
		t=t->next;
	}
}

int add_node(int val)
{
	struct stud *new,*t;
	new=malloc(sizeof(struct stud));

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
int del_by_val(int val)
{
	struct stud *t;
	for(t=h;t->next!=NULL;t=t->next)
	{

		if(t->next->no==val)
		{
			t->next=t->next->next;
		}

		return 0;
	}
}
