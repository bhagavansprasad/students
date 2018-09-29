#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *N;
};
struct node *h=NULL;

main()
{
	int i;
	for(i=1;i<=10;i++)
	{
		printf("i value=%d\n",i);
		add_node(i);
	}
	display_ll(10);
}

int add_node(int n)
{
	struct node *p,*t;
	p=malloc(sizeof(struct node));
	p->val = n;
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

int display_ll(int n)
{
	struct node *t;
	struct node *p;
	if(t=h)
	{
		printf("------>node value = %d\n",t->val);
		printf("------>node address = %u\n",t->N);
	}

	{
		for(t=h;t->N!=NULL;t=t->N);
		printf("last value---->%d     %u\n",t->val,t);
	}

	for(t=h;t!=NULL;t=t->N)
	{
		if(t->val==n)
		{
			printf("previous value---->%d      %u\n",p->val,p);
			break;
		}
		p=t;
	}
	return 0;
}

