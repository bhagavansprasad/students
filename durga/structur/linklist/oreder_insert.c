#include<stdio.h>
struct node
{
	int data;
	struct node *link;
};
struct node* head = NULL;

int order_insert( int val)
{
	struct node* new, *temp, *prev;
	temp = head;
	new = malloc(sizeof(struct node));
	new->data = val;
	new->link = NULL;
	if(head == NULL)
	{
		head = new;
	}
	else if(val < head->data)
	{
		new->link = head;
		head = new;
	}
	else
	{
		prev = head;
		temp = head->link;
		while(temp != NULL && val > temp->data)
		{
			prev = temp;
			temp = temp->link;
		}
		if(temp == NULL)
		{
			prev->link = new;
		}
		else 
		{
			new->link = temp;
			prev->link = new;
		}
	}

}
void disply()
{
	struct node * tm;
	tm = head;
	while(tm)
	{
	 printf("%d\n", tm->data);
	 tm = tm->link;
	}
}

main()
{
	order_insert(5);
	order_insert(10);
	order_insert(1);
	order_insert(2);
	disply();
}
