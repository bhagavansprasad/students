#include "stdio.h"
#include "stdlib.h"
struct student
{
	int no;
	struct student *next;
};
struct student *h=NULL;
int add_node(int value);
//int add_at_begining(int value);
void display();
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	//add_at_begining(5);
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

/*int add_at_begining(int value)
{
	struct student *new,*t;
	new=malloc(sizeof(struct student));
	new->no=value;
	new->next=h;
	h=new;
}*/
