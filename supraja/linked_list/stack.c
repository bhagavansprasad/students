#include <stdio.h>
#include <stdlib.h>
struct student
{
	int num;
	struct student *node;
};
struct student *top=NULL;
int push_ll(int);
void pop_ll(int);
void display_ll(void);
int main()
{
	push_ll(5);
	push_ll(10);
	push_ll(15);
	push_ll(20);
	pop_ll(20);
	display_ll();
}
int push_ll(int n)
{
	struct student *p,*t;
	p=malloc(sizeof(struct student));
	if(top==NULL)
	{
		top=p;
		p->num=n;
		return 0;
	}
	else
	{
		for(t=p;t!=NULL;t=t->node)
		{
			t->num=n;
			t->node=top;
			top=t;
		}
	}
}
void pop_ll(int n)
{
	struct student *t;
	t=top;
	top=t->node;
	t->node=NULL;
}
void display_ll(void)
{
	struct student *t;
	for(t=top;t!=NULL;t=t->node)
	{
		printf("%d\n",t->num);
	}
}
