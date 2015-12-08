#include <stdio.h>
#include <stdlib.h>
struct node
{
	int no;
	struct node *next;
};
struct node *h = NULL;
void display();
main()
{
	order_insert_node(20);
	order_insert_node(10);
	order_insert_node (5);
	order_insert_node (1);
	order_insert_node (13);
	order_insert_node (12);
	order_insert_node(15);
	display();
}
int order_insert_node(int n)
{
	struct node *new ;
	new=malloc(sizeof(struct node));
	new->no = n;
	struct node *p,*c;
	if(h == NULL)
	{
		h=new;
		new->next=NULL;
		return 0;
	}
	else
	{
		p=c=h;
		for( ;c!=NULL; )
		{
			if(n<(c->no))
			{
				if(c==h)
				{
					new->next=h;
					h = new;
					return 0;
				}
				else
				{
					p->next=new;
					new->next=c;
					return 0;
				}
			}
			p=c;
			c=c->next;
		}
		if(c==NULL)
		{
		p->next=new;
		return 0;
		}
	}
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

		printf("value:%d  address:%p  next value:%p\n", t->no,t->next,t);
		t = t->next;
	}

}
