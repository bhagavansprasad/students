#include <stdio.h>
#include <stdlib.h>
struct student
{
	int val;
	struct student *N;
};
struct student *h=NULL;

main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	//del_node_value(40);
	//	display_ll();
	//del_node_pos(2);
	//modify(1,50);
	display_ll();
	get_in(1,60);
	display_ll();
}

int add_node(int n)
{
	struct student *p,*t;
	p=malloc(sizeof(struct student));
	p->val=n;
	p->N=NULL;
	if(h==NULL)
	{
		h=p;
		return 0;
	}
	for(t=h;t->N!=NULL;t=t->N);
	t->N=p;
	return 0;
}

int display_ll()
{
	struct student *t;
	for(t=h;t!=NULL;t=t->N)
	{
		printf("%d\n",t->val);
		printf("%u\n",t->N);
	}
	return 0;
}

int del_node_value(int n)
{
	int c;
	struct student *t,*pre;
	for(t=h;t!=NULL;t=t->N)
	{
		c=c+1;
		if((t->val)==n)
		{
			if(h==t)
			{
				h=t->N;
				free(t);
				return 0;
			}
			else
			{
				pre->N=t->N;
				free(t);
				return 0;
			}
		}
		pre=t;
	}
}

int del_node_pos(int n)
{
	int c=0;
	struct student *t,*pre;
	for(t=h;t!=NULL;t=t->N)
	{
		c++;
		if(c==n)
		{
			if(h==t)
			{
				h=t->N;
				free(t);
				return 0;
			}
			else
			{
				pre->N=t->N;
				free(t);
				return 0;
			}
		}
		pre=t;
	}
}

int modify(int x,int n)
{
	struct student *t;
	int c=0;
	for(t=h;t!=NULL;t=t->N)
	{
		c=c+1;
		if(c==x)
			t->val=n;
	}
	return 0;
}

int get_in(int x,int n)
{
	struct student *p,*t,*t1;
	int i;
	p=malloc(sizeof(struct student));
	p->val=n;
	p->N=NULL;
	if(h==NULL)
	{
		h=p;
		t=p;
		return 0;
	}
	else if(x==1)
	{
		p->N=h;
		h=p;
		return 0;
	}
	else
	{
		t=h;
		for(i=1;i<(x-1);i++)
		{
			t=t->N;
		}
		t1=t->N;
		t->N=p;
		p->N=t1;
	}
	return 0;
}
