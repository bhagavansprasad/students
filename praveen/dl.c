#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *P;
	int val;
	struct node *N;
};
struct node *h=NULL;
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	display_ll();
}

int add_node(int n)
{
	struct node *new,*t;
	new = (struct node *)malloc(sizeof(struct node));
	new->val = n;
	new->P = NULL;
	new->N = NULL;
	if(h==NULL)
	{
		h = new;
		return 0;
	}
	for(t=h; t->N!=NULL; t = t->N);
	t->N=new;
	new->P=t;
	return 0;
}

int display_ll()
{
	struct node *t;
	for(t=h;t!=NULL;t=t->N)
	{
		printf("%u\n",t->P);
		printf("%d\n",t->val);
		printf("%u\n",t->N);
		printf("\n");
	}
}
