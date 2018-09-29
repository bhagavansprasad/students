#include<stdio.h>
#include<malloc.h>

int addnode(int n);
int delete(int n);
void display();
void reverse();

typedef struct node
{
	struct node *prev;
	int val;
	struct node *next;
}node; 
node *header =NULL;

main()
{

	printf("\n\n DOUBLE LINKED LIST \n\n");

	addnode(10);
	addnode(20);
	addnode(30);
	addnode(5);
	addnode(45);


	addnode(50);
	addnode(60);
    display();
	delete(10);
	display();
	addnode(70);

	delete(30);
	display();




	addnode(25);
	//reverse();
	printf("\n\n");
}

int addnode(int n)
{
	node *new=NULL, *temp=NULL;
	new =malloc(sizeof(node) );
	new->prev=NULL;
	new->val=n;
	new->next=NULL;

	temp=header;

	if(temp==NULL)
	{  
		header=new;
		return 0;
	}

	while(temp->next != NULL)
		temp = temp->next;

	new->prev=temp;
	temp->next=new;

	return 0;
}


void display()
{
	struct node *temp=NULL;
	if(header==NULL)
		printf("\nList is empty \n");
	temp=header;
	while(temp !=NULL)
	{
		printf("  %d",temp->val);
		temp=temp->next;
	}
	printf("\n\n");
}

int delete(int n)
{
    node *temp=NULL ;
    
	for(temp=header; temp!=NULL ; temp=temp->next)
	{ 
		if(header->val == n)
     	{  
		    header=header->next;
			header->prev=NULL;
            free(temp);
		}
        printf("%d", header->val);
		if(temp->val == n)
		{ 
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
		}
	}

	return 0;
}


void reverse()
{
	node *temp=NULL, *old=NULL,*new=NULL;
	temp=header;
	//  printf("\n Reversing the Double linked list \n");

	while(temp->next!=NULL)
		temp=temp->next;

	if(temp->next ==NULL)
	{  
		new=temp;	
		new->next->prev=temp->prev;
		new->prev=NULL;		    	

		while(new->next!=NULL)
		{
			printf(" %d ",new->val);
			new=new->next;
		}

	} 
	return;
}


