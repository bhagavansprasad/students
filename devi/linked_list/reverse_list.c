#include <stdio.h>
#include <stdlib.h>

struct node
{
	int no;
	struct node *n;
};
struct node *h = NULL;



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

void reverse_list()
{
	struct node *t;
	for(t=h;t->n!=NULL;t=t->n);
	h=t;
	printf("t->no-->%d\nt->n-->%u\nh-->%u\nt-->%u",t->no,t->n,h,t);
}


main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	display();
	reverse_list();
	display();
}

