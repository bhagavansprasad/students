#include<stdio.h>
#include <stdlib.h>
struct node 
{
	struct node* prev;
	int val;
	struct node* next;
};
struct node *start = NULL;

/* function for adding node in link list*/
struct node* add_node(int data)
{
	struct node* p, *temp = start, *new;
	new = (struct node*) malloc(sizeof(struct node*));
	if( start == NULL)
	{
		start = new;
		start -> prev = NULL;
		start->val = data;
		start->next = NULL;
		return start;
	}
	while( temp->next != NULL)
	{
		temp = temp->next;
	}
	temp -> next = new;
	p = temp -> next;
	p -> prev = temp;
	p -> val = data;
	p ->next = NULL;
	/*if ( p->next == NULL)
	  {
	  while( p->prev != NULL)
	  {
	  printf("%d\n",p->val);
	  p = p->prev;
	  }

	  }*/
	return start;
}
int display()
{
	struct node *d;
	if( start == NULL)
	{
		printf("list is empty");
	}
	d = start;
	printf("%d\n",*d);
	printf("list is\n");
	while( d != NULL)
	{
		printf("%d\n",d -> val);
		printf("------->adres of d->prev:%u\n",d->prev);
		printf("------->adres of d->next:%u\n",d->next);

		d = d->next;
	}
}
void disply_revrs()
{
	struct node* d;
	d = start;
	while(d->next  != NULL)
		d = d ->next;
	if( d->next  == NULL)
	{
		while( d -> prev != NULL)
		{
			printf("%d\n\n",d->val);
			d = d -> prev;
		}
		if(d->prev ==NULL)
			printf("%d\n",d->val);
	}
}
/* deleting the node*/

void delet_node(struct node* p)
{
	if(start == p)
	{
		start = p->next;
		start->prev = NULL;
		free(p);
	}
	if(p->next !=  NULL)
		p->next->prev = p->prev;
	if(p->prev != NULL)
		p->prev->next = p->next;
	free(p);

}
void my_delet(struct node * p)
{
	struct node * tmp = start;
	if(start == p)
	{
		start = p->next;
		start->prev = NULL;
		free(p);
	}
	while(tmp != NULL)
	{
		if(tmp -> next == p)
		{
			tmp->next = tmp->next->next;
			tmp->next->next->prev = tmp;
			free(p);
		}
		tmp = tmp->next;
		}
		if(p->next == NULL)
		{
			p->prev->next = p->next;
			free(p);
		}
	

}

main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	display();
	my_delet(start->next->next);
	printf("print after the dleting node\n");
	display();
	printf("\n");
	disply_revrs();
}

