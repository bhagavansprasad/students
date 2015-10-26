#include<stdio.h> 
#include<stdlib.h>

struct node
{
	struct node *pre;
	int no;
	struct node *N;
};

struct node *h = NULL;

int add_node(int value);

void display();

int main()
{
	add_node(60);
	add_node(20);
	add_node(30);
	add_node(40);
	display();
}
void display()
{
	struct node *t=h;
	while(t!=NULL)
	{
		printf("%d\n",t->no);
		t = t->N;
	}
}

int add_node(int value)
{
	struct node *new,*t;
	new = malloc(sizeof(struct node));
	new->pre = NULL;
	new->no = value;
	new->N  = NULL;

	if(h == NULL)
	{
		h = new;
		return 0;
	}

	for(t = h; t->N!= NULL;t=t->N);
	t->N = new;
	t->N->pre = t;
	return 0;
}


