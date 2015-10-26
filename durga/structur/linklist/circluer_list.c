#include<stdio.h>
struct node
{
int data;
struct node *link;
};
struct node *head = NULL;

int add_cir_node(int val)
{
	struct node *new, *temp;
	temp = head;
	new = malloc(sizeof(struct node));
	new->data = val;
	new->link = NULL;
	if(head == NULL)
	{
		head = new;
		new->link = head;
		return 0;
	}

	while(temp->link != head)
		temp = temp->link;

	temp->link = new;
	new->link = head;
		return 0;

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
	add_cir_node(10);
	add_cir_node(20);
	add_cir_node(30);

	disply();
}

