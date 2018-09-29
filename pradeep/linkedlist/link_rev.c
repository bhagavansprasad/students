#include<stdio.h> 
#include<stdlib.h>

struct node
{
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
	reverse_node(40);
	reverse_node(30);
	reverse_node(20);
	reverse_node(10);
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
	new->no = value;
	new->N  = NULL;

	if(h == NULL)
	{
		h = new;
		return 0;
	}

	for(t = h; t->N!= NULL;t=t->N);
	t->N = new;
	return 0;
}
int reverse_node(int value)
{
	struct node *curr,*pre;
	if(curr->N == NULL)
	{
		h=curr;
		printf("%d",h);
		curr->N=pre->N;
		return 0;
	}
	for(curr=h;curr->N!= NULL;curr=pre,pre=pre->N)
	{
		if(curr->no==value)
		{
			if(curr==h)
			{
				h=pre->N;
			}
			else
				curr->N=pre->N;
			return 0;
		}
	}
}
