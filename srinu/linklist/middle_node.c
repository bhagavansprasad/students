#include <stdio.h>
#include <stdlib.h>
int add_node(int value);
void display();

struct student
{
	int no;
	struct student *next;
};
struct student *h=NULL;
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(40);
	display();
	middle_node(h);
}
int add_node(int value)
{
	struct student *new,*t;
	new = malloc(sizeof(struct student));
	new->no=value;
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
void display()
{
	struct student *t=h;
	while(t!=NULL)
	{
		printf("value : %d    address value : %p     next value : %p\n",t->no,t->next,t);
		t=t->next;
	}
}

int middle_node(struct student *h)
{
	struct student *first, *second;
	first=second=h;
	if(h!=NULL)
	{
		while(second!=NULL && first->next!=NULL)
		{
			second=second->next;
			first=first->next->next;
		}
		printf("middle node is %d\n",second->no);
	}
}


