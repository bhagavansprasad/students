#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int addnode(int n);
void display();

typedef struct node 
{
	int data;
	struct node *next;
}node;

node *header=NULL,*rear=NULL;
int count=0;

int main()
{

	printf("\n\n Single linked list creation \n");

	addnode(10);
	addnode(20);
	addnode(30);
	addnode(40);
	addnode(5);
	display();


}
void display()
{
	while(header !=NULL)
	{
		printf(" %d ",header->data);
		header= header->next;
	}
	printf("\n\n");
}


int addnode(int n)
{
	struct node *new;
	if(count<5)
	{
		new=malloc(sizeof(struct node *));
		new->data=n;
		new->next=NULL;

		if(header == NULL)
		{	
			header=new;
			rear=new;
		}	

		else	
		{
			rear->next=new;
			rear=new;
		}		
		count++;
	}	 
	else
		printf("U should not add more than 5 nodes for the linked list \n\n");
	return 0;
}

