#include<stdio.h>
#include<stdlib.h>
int add(int);
void display(void);
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
