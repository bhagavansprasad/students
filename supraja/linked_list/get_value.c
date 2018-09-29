#include <stdio.h>
#include <stdlib.h>
struct student
{
	int val;
	struct student *n;
};
struct student *h=NULL;
int main()
{
	int t1,t2,t3;
	add_node(2);
	add_node(3);
	add_node(4);
	add_node(5);
	display_ll();
	t1=get_first();
	t2=get_next(4);
	t3=get_last();
	printf("%d\n",t1);
	printf("%d\n",t2);
	printf("%d\n",t3);
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
int display_ll()
{
	struct student *t;
	for(t=h;t!=NULL;t=t->n)
	{
		printf("%d\n",t->val);
	}
}
int get_first(void)
{
	struct student *p;
	p=h;
	return p->val;
}
int get_next(int n)
{
	struct student *p;
	struct student *p1;
	for(p=h,p1=h->n;p1!=NULL;p=p->n,p1=p1->n)
	{
		if(p->val==n)
		{
			return p1->val;
		}
	}
}	
int get_last(void)
{
	struct student *p;
	for(p=h;p->n!=NULL;p=p->n);
	return p->val;
}
