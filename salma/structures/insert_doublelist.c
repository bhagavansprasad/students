//after node insertion
#include<stdio.h>
#include<stdlib.h>
int add(int);
void display(void);
int insert(int ,int);
struct node 
{
	struct node *p1;
	int n;
	struct node *p2;
};
struct node *h=NULL;
struct node *t=NULL;
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	display();
	insert(40,60);
	display();
	insert(20,25);
	display();
}
int add(int value)
{
	struct node *temp=h;
	t= /*(struct node *)*/malloc(sizeof(struct node));
	t->p1=NULL;
	t->n=value;
	t->p2=NULL;
	if(h==NULL)
	{
		h=t;
		return(0);
	}
	while(temp->p2!=NULL)
	{
		temp=temp->p2;
	}
	temp->p2=t;
	t->p1=temp;
}
void display(void)
{
	struct node *temp=h, *i;
	for(i=temp;temp->p2!=NULL;temp=temp->p2)
	{
		printf("%d\t",temp->n);
	}
	if(temp->p2==NULL)
		printf("%d\n",temp->n);
	for(;temp->p1!=NULL;temp=temp->p1)
		printf("%d\t",temp->n);
	if(temp->p1==NULL)
		printf("%d\n",temp->n);
}
int insert(int item,int value)
{
	struct node *i;
	if(h==NULL)
	{
		printf("list is empty\n");
		return(0);
	}
	for(i=h;i->n!=item;i=i->p2)
	{
		if(i->p2==NULL)
		{
			printf("no such number exists\n");
			return(0);
		}
	}
	if(i->p2!=NULL && i->n==item)
	{
		t=malloc(sizeof(struct node));
		t->p2=i->p2;
		i->p2->p1=t;
		i->p2=t;
		t->p1=i;
		t->n=value;
		return(0);
	}
	if(i->p2==NULL&&i->n==item)
	{
		t=malloc(sizeof(struct node));
		i->p2=t;
		t->p1=i;
		t->p2=NULL;
		t->n=value;
		return(0);
	}
}
