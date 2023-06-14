#include "stdio.h"
#include "stdlib.h"

struct node
{
	int v;
	struct node *n;
};

struct node *h = NULL;

int dump_list(void)
{
	struct node *temp = h;

	for(temp = h; temp != NULL; temp = temp -> n)
	{
		printf("%p:%d\n", temp, temp->v);
		fflush(stdout);
	}

	printf("\n");
	return 0;
}

int reverse_list(void)
{
	struct node *t, *p=NULL, *c, *n;
	c = h;
	while(c != NULL)
	{
		n = c->n;
		c->n = p;
		p = c;
		c = n;
	}
	h = p;
	return 0;
}

int add_node(int d)
{
	printf("%d ", d);
	struct node *temp;
	struct node *n = (struct node *) malloc(sizeof(struct node));
	n->v = d;
	n->n = NULL;

	if (h == NULL)
	{
		h = n;
		return 0;
	}

	for(temp = h; temp->n != NULL; temp = temp -> n);
	temp->n = n;

	return 0;
}

int add_nodes()
{
	int a[] = {2, 4, 1, 6, 3};
	int i = 0;

	for (i = 0; i < sizeof(a)/sizeof(int);i++)
		add_node(a[i]);
}

int main()
{
	add_nodes();
	printf("\n");
	dump_list();
	reverse_list();
	dump_list();
	return 0;
}
