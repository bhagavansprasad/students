#include<stdio.h>
#include<stdlib.h>
int addnonde(int n);
void display();
int delete(int n);

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

int delete(int n)
{
	printf("After deletion of %d ",n);
	struct node *temp = NULL;
	
	if(head == NULL)
	{
		printf("No Node in the List\n");
		return 0;
	}
	
	if(head->val == n)
	{
		temp = head;
		head = head->next;
		temp->next->prev = NULL;
		free(temp);
		return ;
	}
	
	for(temp = head ; temp != NULL ; temp = temp->next)
	{
		if( temp -> val == n)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			return 0;
		}
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
	
	delete(30);
	display();
	
	delete(10);
	display();
}
