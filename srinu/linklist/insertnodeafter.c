#include <stdio.h>
#include <stdlib.h>
int add_node(int value);
void display();
int insert_node_after(int value,int pos);

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
	printf("before inserted values \n");
	display();
	insert_node_after(11,3);
	printf("after inserted values \n");
	display();
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
int insert_node_after(int value,int pos)
{
	int i=0;
	struct student *new,*t;
	t=h;
	for(i=1;i<pos-1 & t!=NULL;i++)
		t=t->next;
	if(t==NULL)
	{
		printf("elements are less than : %d\n",pos);
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
