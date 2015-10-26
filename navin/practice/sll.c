/* Program on Single Linked list by adding nodes and printing them, reverse
   printing the nodes by using recursion and printing them , deleting the last
   node and printing the remaining nodes*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int val;
	struct node *next;
}Node;

struct node *head=NULL,*temp;

int add_node(int val);
void display(struct node *head);
void reverse(Node *head);
void delete(Node *head);

int main(void)
{
	int i;

	for(i=0;i<7;i=i+2)
		add_node(i);

	printf("Added Nodes  : ");
	display(head);
	printf("\n");

	printf("Reverse Order : ");
	reverse(head);
	printf("\n");

	delete(head);

	printf("After deleteing the last node \n" );
	display(head);
	printf("\n");



}

int add_node(int i)
{

	Node *new=malloc(sizeof(Node));
	new->val=i;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		return 0;	 
	}
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=new;

}   

void display(Node *head)
{
	while(head!=NULL)
	{
		printf(" %d ",head->val);
		head=head->next;
	}
}

void reverse(Node *head)
{
	if(head->next!=NULL)
		reverse(head->next);

	printf(" %d ",head->val);
}

void delete(Node *head)
{
	for(temp=head;temp->next->next!=NULL;temp=temp->next);
	temp->next=NULL;

}



