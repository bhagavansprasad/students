#include "stdlib.h"
#include <stdio.h>
typedef struct node_t
{
	int val;
	struct node_t *next;
}node;
node *head = NULL;

int addnode(int n)
{
	node *new=NULL, *temp=NULL;
	new = malloc(sizeof(node));
	new->val=n;
	new->next =NULL;

	if(head == NULL)
	{
		head = new;
		return 0;
	}
	for(temp = head; temp->next != NULL; temp= temp->next);
	temp->next = new;
}
void display()
{
	node *temp;
	temp = head;
	printf("\nList values are:");
	while(temp != NULL)
	{
		//printf("|%u|-->|%d|\t",temp,temp->val);
		printf("%d\t",temp->val);
		temp = temp->next;
	}
	printf("\n");
}
void delete_last5th_node()
{
	int i;
	node *temp1=NULL, *temp2= NULL, *old=NULL;
	temp1 =temp2= head;
	printf("After deleting last 5th node:");
	for(i=1; i<=5 ;i++)
		temp1=temp1->next;

	while(temp1 != NULL)
	{	old = temp2;
		//temp1 = temp1->next;
		temp2 = temp2->next;
	}
	old->next = temp2->next;
	free(temp2);
	return ;
}

int main()
{
	addnode(10);
	addnode(100);
	addnode(140);
	addnode(130);
	addnode(13);
	addnode(130);
	addnode(111);
	addnode(133);
	addnode(132);
	addnode(135);
	addnode(131);
	addnode(135);
	addnode(112);
	addnode(200);
	addnode(55);
	addnode(146);
	addnode(143);
	addnode(110);
	display();
	delete_last5th_node();
	display();
}

