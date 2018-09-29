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
	order_ll();
	delete_node(8);
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
void order_ll()
{
	struct student *p,*c,*t;
	t=malloc(sizeof(struct student));
	for(p=h;p!=NULL;p=p->n)
	{
		for(c=p->n;c!=NULL;c=c->n)
		{
			if(p->val>c->val)
			{
				t->val=p->val;
				p->val=c->val;
				c->val=t->val;
			}
		}
	}
}	
int delete_node(int x)
{
	struct student *p,*t,*p1=NULL;
	for(t=h;t!=NULL;t=t->n)
	{
		p=t;
		if(t->val==x)
		{
			if(h==p)
			{
				h=t->n;
				free(p);
				return(0);
			}
			else
			{
				p1->n=t->n;
				free(p);
				return (0);
			}
		}
		p1=t;
	}
}
int display_ll()
{
	struct student *t;
	for(t=h;t!=NULL;t=t->n)
	{
		printf("%d\n",t->val);
	}
}
