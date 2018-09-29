#include <stdio.h>
#include <malloc.h>
struct node
{
	int val;
	struct node *N;
};
struct node *h = NULL;

main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	display();
}
int add_node(int n)
{
	struct  node *p, *t;
	p = malloc(sizeof(struct node));
	p -> val = n;
	p -> N = NULL;
	if(h == NULL)
	{
		h = p;
		return 0;
	}
	for(t = h; t -> N != NULL; t = t -> N);
	t -> N = p;
}
int display()
{
	struct node *t;
	for(t = h; t != NULL; t = t -> N)
	{
		printf("node val is : %d\n", t -> val);
	}
}
