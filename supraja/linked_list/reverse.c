#include <stdio.h>
#include<stdlib.h>
void order_ll(void);
struct student
{
	int val;
	struct student *n;
};
struct student *h=NULL;
main()
{
	add_node(5);
	add_node(4);
	add_node(8);
	add_node(2);
	add_node(1);
	add_node(10);
	reverse_node();
	display_ll();
}
int add_node(int x)
{
	struct student *p,*t;
	p=malloc(sizeof(struct student));
	p->val=x;
	p->n=NULL;
	if(h==NULL)
	{
		h=p;
		return 0;
	}
	for(t=h;t->n!=NULL;t=t->n);
	t->n=p;
}
int reverse_node()
{
	struct student *p=NULL,*t=NULL;
	while(h!=NULL)
	{
		t=h;
		h=h->n;
		t->n=p;
		p=t;
	}
	h=t;
	return 0;
}
int display_ll()
{
	struct student *t;
	for(t=h;t!=NULL;t=t->n)
	{
		printf("%d\n",t->val);
	}
}
