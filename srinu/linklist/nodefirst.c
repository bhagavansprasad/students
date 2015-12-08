#include <stdio.h>
#include <stdlib.h>
struct node
{
	int no;
	struct node *next;
};
struct node *h=NULL;
int add_node(int n);
void display();
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	display();
}
void display()
{
	struct node *t=h;
	while(t!=NULL)
	{
		printf("value:%d\t   address:%p\t    next value:%p\n",t->no,t,t->next);
		t=t->next;
	}
}

int add_node(int n)
{
	struct node *new,*p;
	new=malloc(sizeof(struct node));
	{
		new->no=n;
		new->next=NULL;
    }
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	p=h;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=new;
}
