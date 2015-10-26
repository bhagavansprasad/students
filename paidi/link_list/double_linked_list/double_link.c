#include"stdio.h"
#include"stdlib.h"

int addnonde(int n);
void display();
int delete(int n);
void reverse();

typedef struct node_t
{
	struct node_t *prev;
	int val;
	struct node_t *next;
}node;

node *head=NULL;


int addnode(int n)
{
	node *new=NULL,*prev=NULL,*temp=NULL;
	new=malloc(sizeof(node));
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
	node *temp=NULL;
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
	node *temp = NULL; 
	node *current = head;

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

int delete(int n)
{
	printf("After deletion of %d ",n);
	node *temp = NULL;
	if(head == NULL)
	{
		printf(" No Node in the List\n");
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
	
	addnode(7);
	display();
	
	addnode(70);
	display();

	reverse();
	display();
}

