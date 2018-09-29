#include <stdio.h>
#include "stdlib.h"
void display(void);
int i=0;
struct node
{
	int no;
	struct node *n;
};
struct node *h = NULL;
main()
{
	int delete_reply;
	int j;
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	display();
	j = find_middle_node();
	printf("middle node-->%d and no in node-->%d\n",i,j);
	delete_reply = delete_node(10);
	if(delete_reply == 1)
	{
		printf("element found\n");
	}
	else
	{
		printf("element not found\n");
	}
	display();
}

int find_middle_node()
{
	struct node *t,*p;	
	for(t=h,p=h;p!=NULL;t=t->n,p=p->n->n)
	{
		i++;
		printf("i-->%d\nt->no-->%d\np->no-->%d\n",i,t->no,p->no);
		if(p->n == NULL)
		break;
	}
return t->no;
}


int add_node(int n)
{
	struct node *new = (struct node *) malloc(sizeof(struct node));
	new->no = n;
	new->n = NULL;
	struct node *t;

	if(h == NULL)
	{
		h = new;
		return 0;
	}
	for(t=h;t->n!=NULL;t=t->n);
	t->n=new;

	return 0;

}

int delete_node(int val)
{
	struct node *t=h,*p;
	int i=0;

	if(t==NULL)
	{
		printf("no nodes\n");
	}
	if(t->no == val && t->n == NULL)
	{
		h=NULL;
		i=1;
		free(t);
	}
	for(t=h;t!=NULL;p=t,t=t->n)
	{

		if(t->no==val && t == h)
		{
			h=t->n;
			free(t);
			i=1;
			break;
		}
		if(t->no == val && t->n!=NULL)
		{
			i=1;
			p->n = t->n;
			free(t);
			break;
		}
		if(t->no == val && t->n==NULL)
		{
			i=1;
			p->n = NULL;
			free(t);
			break;
		}
	}
	return i;
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
		t = t->n;
	}
}
