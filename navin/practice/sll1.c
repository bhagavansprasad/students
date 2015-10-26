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
void delete(int i);

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

	 delete(4);

	printf("After deleteing the node \n" );
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

void delete(int i)
{
	//1 for(temp=head;temp->next->next!=NULL;temp=temp->next);
	//1 temp->next=NULL;
     
	 Node *temp2=NULL;
     Node *temp1=head; 
	 for(temp=temp1;temp->next->val!=i;temp=temp->next)
        {
			 temp2=temp1->next;
		}
			
			if(temp2==head)
			 {
			   head=head->next;
		     }
			 else 
			 {
			   head->next=head->next->next;
			 }
    	
}



