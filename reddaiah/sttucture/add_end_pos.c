#include "stdio.h"
#include "stdlib.h"
struct student 
{
	int no;
	struct student *next;
};
struct student *h=NULL;
void del_beg(int n);
int add_node(int val);
int add_atbeg(int n);
int add_atend(int a);
int add_atpos(int b,int pos);
void display_ll(void);
main()
{
	printf("%d\n",sizeof(struct student));
	add_node(10);
	add_node(20);
	add_node(30);
	add_atbeg(5);
	add_atend(50);
	add_node(40);
	add_atpos(25,4);
	del_beg(5);
	display_ll();
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
void display_ll(void)
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
int add_atend(int a)
{
	struct student *new,*t;
	new=malloc(sizeof(struct student));
	new->no=a;
	new->next=NULL;
	t=h;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new;
	return 0;
}
int add_atpos(int b,int pos)
{
	int i;
	struct student *new,*t;
	t=h;
	for(i=1;i<pos-1 && t!=NULL;i++)
		t=t->next;
	if(t==NULL)
	{
		printf("the elements are less than the %d elements\n",pos);
	}
	else
	{
		new=malloc(sizeof(struct student));
		new->no=b;
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
void del_beg(int n)
{
	struct student *new;
	new=h;
	h=h->next;
	free(new);
}
