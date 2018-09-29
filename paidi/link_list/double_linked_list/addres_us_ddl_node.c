#include"stdio.h"
#include"stdlib.h"

int addnode(int n);
void display();

struct node
{
	struct node *prev;
	int val;
	struct node *next;
}*head=NULL;


int addnode(int n)
{
	struct node *new=NULL,*prev=NULL,*temp=NULL;
	new=malloc(sizeof(struct node));
	new->prev=NULL;
	new->val=n;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		return;
	}
	temp=head;

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	new -> prev=temp;
	temp -> next=new;

}

void display()
{
	struct node *temp=NULL;
	temp=head;

	printf("the elements are\n");

	while(temp!=NULL)
	{
		printf("%d\n",temp->val);
		temp=temp->next;
	}
}

void delete_node(struct node *temp)
{
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}
void main()
{
    struct node *temp;
	int pos=1;
	addnode(10);
	addnode(28);
	addnode(30);
	addnode(40);
	addnode(50);
	addnode(60);
	display();
	for(temp=head ; pos<2 && temp->next!=NULL ; temp=temp->next,pos++);
	printf("position : %d\n", pos);
	delete_node(temp);
	display();
	
}

