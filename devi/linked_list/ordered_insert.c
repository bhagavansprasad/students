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
	order_add_node(20);
	order_add_node(10);
	order_add_node(5);
	order_add_node(1);
	order_add_node(15);
	//add_node(30);
	//add_node(40);
	//add_node(50);
	display();
}


int order_add_node(int n)
{
	struct node *new = (struct node *) malloc(sizeof(struct node));
	new->no = n;
	new->n = NULL;
	struct node *t,*p;
	if(h == NULL)
	{
		h=new;
		return 0;
	}

	for(t=h;t!=NULL;p=t,t=t->n)
	{

		if(t->n == NULL)
		{
			if(t->no < new->no)
			{
				t->n = new;
				break;
			}
			else
			{
				new->n=t;
				h = new;
				break;
			}
		}
		else
		{
			if(t->no > new->no)
			{
				new->n = t;
				h = new;
				break;
			}
			else
			{
				if(new->no > t->no && new->no < t->n->no)
				{
					new->n = t->n;
					t->n = new;
					break;
				}
			}
		}
	}

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
