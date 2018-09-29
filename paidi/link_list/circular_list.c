#include<stdio.h>
#include<stdlib.h>
void add_circular(int);
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
main()
{
	add_circular(10);
	add_circular(20);
	add_circular(30);
	add_circular(40);
	add_circular(50);
	display();
}

void add_circular(int n)
{
	struct node *temp,*new;
	new=malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	temp=head;
	if(head==NULL)
	{
		head=new;
		new->next=head;
	}
	else
	{
		while(temp->next !=head)
			temp=temp->next;      
		temp->next=new;
		new->next=head;
	}
}

void display()
{
	struct node *temp;
	temp=head;
	printf("%d\n",temp->data);
	temp=temp->next;
	while(temp!=head)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
