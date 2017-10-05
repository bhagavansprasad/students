#include<stdio.h>
#include<stdlib.h>
int addnonde(int n);
void display();

struct node
{
	struct node *prev;
	int val;
	struct node *next;
};

struct node *head=NULL;

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
	for(temp = head; temp -> next != NULL; temp = temp -> next);
	new -> prev=temp;
	temp -> next=new;
}

void display()
{
	struct node *temp=NULL;

	printf("the elements are\n");

	for(temp = head; temp -> next != NULL; temp = temp -> next)
	{
		printf("%d\n",temp->val);
	}
}	

void main()
{
	addnode(10);
	addnode(18);
	addnode(30);
	addnode(90);
	addnode(55);
	addnode(5);
	display();
}

