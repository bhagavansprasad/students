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
int add_at_begn(int val);
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_end(5);
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
int add_end(int val)
{
	struct stud *new,*t;
	new=malloc(sizeof(struct stud));
	new->no=val;
	new->next=NULL;
	return 0;
}


