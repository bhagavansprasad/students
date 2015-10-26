#include "stdio.h"
#include "stdlib.h"

struct node
{
	int no;
	struct node *N;
};
struct node *h = NULL;
int dump_list(void);
int add_node(int val);

main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	dump_list();

}

int dump_list(void)
{
	struct node *new,*t = h;
	int i = 1;

	printf("\nDumping list....\n");
	while(t != NULL)
	{
		printf("%3d. %8d %10p %10p\n", i++, t->no, t, t->N);
		t = t->N;
	}

	return 0;
}

int add_node(int val)
{
	struct node *new, *t;
	new = (struct node *)malloc(sizeof(struct node));
	new->no = val;
	new->N = NULL;

	if(h == NULL)
	{
		h = new;
		return 0;
	}
	t = h;
	while(t->N != NULL)
	{
		t = t->N;
	}
	t->N = new;
	new->N = h;
	return 0;
}
