#include<stdio.h> 

#include<stdlib.h>

struct node
{
	struct node *p;
	int no;
	struct node *N;
};

struct node *h = NULL;

int add_node(int value);

int delete_node(int value);

void display();

int main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	display();
	delete_node(10);
	delete_node(30);
	delete_node(50);
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
	struct node *new,*pre,*t;
	new = malloc(sizeof(struct node));
	new->p = NULL;
	new->no = value;
	new->N  = NULL;

	if(h == NULL)
	{
		h = new;
		return 0;
	}

	for(t = h; t->N!= NULL;t=t->N);
	t->N = new;
	t->N->p = t;
	return 0;
}
int delete_node(int value)
{
	struct node *curr,*pre;

	for(curr=h;curr->N!=NULL;pre=curr,curr=curr->N)
	{
		if(curr->no==value)
		{
			if(curr==h)
			{
				h=curr->N;
				free(curr);
				return 0;
			}
			else
			{
				pre->N=curr->N;
				curr->N->p=pre;
				free(curr);
				return 0;
			}
		}
	}
	if(curr->N==NULL)
	{
		pre->N=NULL;
		free(curr);
		return 0;
	}
}
