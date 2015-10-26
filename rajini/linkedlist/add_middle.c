#include "stdio.h"
#include "stdlib.h"
struct student
{
	int no;
	struct student *next;
};

struct student *h=NULL;
int add_node(int value);
int insert_by_pos(int value,int pos);
void display();

main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	insert_by_pos(105,1);
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

int insert_by_pos(int value,int pos)
{
	int i=0;
	struct student *new,*t;
	t=h;
	for(i=1;i<pos-1 & t!=NULL;i++)
		t=t->next;
	if(t==NULL)
	{
		printf("elements r less than %d elements \n",pos);
	}
	else
	{
		new=malloc(sizeof(struct student));
		new->no=value;
		if(pos==1)
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
}


