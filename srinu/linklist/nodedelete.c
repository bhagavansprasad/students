#include "stdio.h"
#include "stdlib.h"
struct student
{
	int no;
	struct student *next;
};

struct student *h=NULL;
int add_node(int value);
void delete_begin(int value);
void display();

main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	delete_begin(10);
	display();
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

void delete_begin(int value)
{
	struct student *new;
	new=h;
	h=h->next;
	free(new);
}

