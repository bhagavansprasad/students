#include "stdio.h"
#include "stdlib.h"

struct node
{
	int no;
	struct node *N;
	struct node *P;
};
struct node *h = NULL;
int add_node(int val);
int add_at_beg(int val);
int add_at_pos(int val,int pos);
int add_at_end(int val);
int del_by_val(int val);
void display(void);


main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_at_beg(5);
	add_at_pos(25,3);
	add_at_end(60);
	display();
	del_by_val(5);
	display();
	del_by_val(30);
	display();
	del_by_val(60);
	display();
}
void display(void)
{
	struct node *t = h;
	while(t != NULL)
	{
		printf("no :%4d P :%10p N :%10p\n",t->no,t->P,t->N);
		t = t->N;

	}
	printf("\n");
}
int add_node(int val)
{
	struct node *new,*t;
	new = (struct node *)malloc(sizeof(struct node));

	new->no = val;
	new->N = NULL;
	new->P = NULL;

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
	new->P = t;
	return 0;
}
int add_at_beg(int val)
{
	struct node *new, *t = h;
	new = (struct node *)malloc(sizeof(struct node));
	new->no = val;
	new->N = t;
	new->P = NULL;
	h = new;
	t->P = new;
	return 0;
}
int add_at_pos(int val,int pos)
{
	struct node *new,*t = h;
	int c = 0;
	new =(struct node *)malloc(sizeof(struct node));

	new->no = val;
	new->N = new->P = NULL;
	while(t->N != NULL)
	{
		if(c == pos)
		{
			t->P->N = new;
			new->N = t;
			t->P = new;
			new->P = t->P;

			return 0;
		}
		t = t->N;
		c++;
	}
}
int add_at_end(int val)
{
	struct node *new,*t = h;
	new = (struct node *)malloc(sizeof(struct node));
	new->no = val;
	new->N = new->P = NULL;
	while(t != NULL)
	{
		if(t->N == NULL)
		{
			new->P = t;
			t->N = new;
			return 0;
		}
		t = t->N;
	}
}
int del_by_val(int val)
{
	struct node *t = h;
	if(h->no == val)
	{
		t->N->P = NULL;
		h = t->N;
		return 0;
	}
	while(t != NULL)
	{
		if(t->no == val)
		{
			if(t->N == NULL)
			{
				t->P->N = NULL;
				free(t);
				return 0;
			}

			t->P->N = t->N;
			t->N->P = t->P;
			free(t);
			return 0;
		}
		t = t->N;
	}
}
