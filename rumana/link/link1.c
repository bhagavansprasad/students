#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *p;
};
struct node *h=NULL;
struct node *new;
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	insert_node(5);
	display();
}
int add(int x)
{
	struct node *temp;
	new=malloc(sizeof(struct node));
	new->n=x;
	new->p=NULL;
	if(h==NULL)
	{
		h=new;
		return(0);
	}
	for(temp=h;temp->p!=NULL;temp=temp->p);
		temp->p=new;
}
int insert_node(int x)
{
	new=malloc(sizeof(struct node));
	new->n=x;
	new->p=h;
	h=new;
}
int display(int n)
{
	struct node *temp;

	for(temp=h;temp!=NULL;)
	{
		printf("%d\n",temp->n);
		temp=temp->p;
	}
}



