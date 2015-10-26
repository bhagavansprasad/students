#include<stdio.h> 
#include<stdlib.h>

struct node
{
    struct node *pre;
	int no;
	struct node *N;
};

struct node *h = NULL;


void dump_list()
{
	struct node *t;

	for(t=h;t!=NULL;t=t->N)
	{
		printf("%5d", t->no);
	}

	printf("\n");
}

void display()
{
	struct node *t;
	for(t=h;t!=NULL;t=t->N)
	{
		printf("%d\n",t->no);
	}
}


int add_node(int value)
{
	struct node *new,*t,*pre;

	printf("adding node with value %d\n", value);

	
	new = malloc(sizeof(struct node));
	
	new->pre=NULL;
	new->no = value;
	new->N  = NULL;


	if(h == NULL)
	{
		h = new;
		return 0;
	}

	for(t = h; t->N!= NULL;t=t->N);
	t->N = new;
	t->N->pre=t;
	return 0;
}

/*
int delete_node(int value)
{
	struct node *curr,*pre;

	printf("deleting node with value %d\n", value);
	
	for(curr=h;curr!=NULL;pre=curr,curr=curr->N)
	{
		if(curr->no==value)
		{
			if(curr==h)
				h=curr->N;
			else 
				pre->N=curr->N;

			free(curr);
		}
	}
	return 0;
}
*/

int main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_node(60);
	dump_list();


	add_node(23);
	add_node(36);
	dump_list();

/*	delete_node(100);
	dump_list();

	delete_node(23);
	dump_list();

	delete_node(20);
	dump_list();
*/

}


