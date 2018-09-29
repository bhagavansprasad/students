#include<stdio.h>
#include<stdlib.h>
int addnonde(int n);
void display();
void reverse();
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
void reverse()
{
	struct node *temp = NULL; 
	struct node *current = head;
	while (current !=  NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;             
		current = current->prev;
	}     
	if(temp != NULL )
		head = temp->prev;
	printf("After Reverse  ");
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

	reverse();
	display();
}
