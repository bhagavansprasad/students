#include<stdio.h>
#include<stdlib.h>
struct student
{
	int val;
	struct student *N;
};
struct student *h = NULL;
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	modify_by_val(2,50);
	insert_node(1,60);
	del_by_pos(4);
	del_node_by_val(30);
	
	disply_ll();
}
int add_node(int n)
{
	struct student *p,*t;
	p=malloc(sizeof (struct student));
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
int disply_ll()
{
	struct student *t;
	for(t=h;t!=NULL;t=t->N)
	{
		printf("%d\n",t->val);
		printf("%p\n",t->N);
	}
	return 0;
}
int del_node_by_val(int n)
{
	struct student *cur, *t, *pre;
	for (t=h;t!=NULL;t=t->N)
	{
		cur = t;
		if((t->val)== n)
		{
			if(h==cur)
			{
			h = t->N;
			free(cur);
			return 0;
			}
			{
				pre->N = cur->N;
				free(cur);
				return 0;
			}
		}
	pre = cur;	
	}
}
int del_by_pos(int n)
{
	struct student *t, *p;
	int c= 0;
	for(t = h;t != NULL;t = t->N)
	{
		c = c+1;
		if(c==n)
		{
			if(h==t)
			{
				h=t->N;
				free(t);
				return 0;
			}
			{
			p->N = t->N;
			free(t);
			return 0;
			}
		}
		p = t;
	}
}
 int modify_by_val(int x,int n)
 {
 	struct student *t;
	int c = 0;
	for (t = h;t != NULL; t = t->N)
	{
		c = c+1;
		if(c == x)
		{
			t->val = n;
		}
	}
	return 0;
 }
int insert_node(int x,int n)
{
	struct student *new,*t,*prev;
	t=h;
	new=malloc(sizeof(struct student));
	new->val=n;
	new->N=NULL;
	while(t!=NULL)
	{
		if(t->val==n)
		{
			if(t==h)
			{
				printf("\nthis operation is insertion");
				return 0;
			}
			else
			{
				prev->N=new;
				new->N=t;
				free(t);
				return 0;
			}
		}
		else
		{
			prev=t;
			t=t->N;
		}
	}
}


