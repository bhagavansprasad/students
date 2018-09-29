#include <stdio.h>
#include <stdlib.h>
struct node
{
	int no;
	struct node *next;
};
struct node *h = NULL;
int add_node(int n)
{
	struct node *new;
	new=malloc(sizeof(struct node));
	new->no = n;
	new->next = NULL;
	struct node *t;
	if(h == NULL)
	{
		h = new;
		return 0;
	}
	for(t=h;t->next!=NULL;t=t->next);
	t->next=new;
	return 0;
}
void display(void)
{
	struct node *t=h;
	if(t==NULL)
	{
		printf("no elements to print\n");
	}
	while(t!=NULL)
	{
		printf("no-->%d\n", t->no);
		t = t->next;
	}
}
void reverse_list()
{
	struct node *t,*p=NULL,*next;
	t=h;
	while(t!=NULL)
	{
	next=t->next;
	t->next=p;
	p=t;
	t=next;
	}
	h=p;
}
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	printf("before reverse\n");
	display();
	printf("after reverse\n");
	reverse_list();
	display();
}
