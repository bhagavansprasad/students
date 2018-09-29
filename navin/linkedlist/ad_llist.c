#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *next;
};

struct node *head=NULL;
struct node *curr=NULL;
int add(int val);
int order();
int printlist();

int main()
{

	struct node *ptr;
	int i;

	for(i=0;i<10;i++)
		add(i);


	for(i=5;i<10;i++)
		add(i);


	//	for(i=4;i>0;i--)
	//		add(i);

	int z=order();

	if(z==0)
		printf("Ascending Order : ");
	else 
		printf("Descending Order");

	printlist();

}


int order()
{
	struct node *ptr=head;
	struct node *temp=NULL;

	while(ptr!=NULL)
	{
		if(head==NULL)
		{
			printf("No nodes in list");

		}	


		for(temp=head;ptr->next!=NULL;temp=temp->next)
		{

			if(ptr->val < ptr->next->val)
				return 0;
			else 
				return 1;
		} 
	}	

}



int create(int val) 
{
	struct node *ptr = malloc(sizeof(struct node));

	if(ptr==NULL)
	{
		printf("Node creation failed");
		return 1;
	}
	ptr->val=val;
	ptr->next=NULL;
}

int add(int val)
{
	if(head==NULL)
	{
		create(val);
		return 0;
	}
	struct node *ptr=malloc(sizeof(struct node));

	if(ptr==NULL)
	{
		printf("Node creation failed");
		return 1;

	}
    while(head->next!=NULL);
	ptr->val=val;
	ptr->next=NULL;

	/*	if(k)
		{ 
		curr->next=ptr;
		curr=ptr;
		}

		else	
		{
		ptr->next=head;
		head=ptr;
		} */

	return 0;

}

int printlist()
{
	while(head!=NULL)
{
	printf("%d", head->val);
	head=head->next;

}

}





