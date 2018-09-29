#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *p;
};
struct node *start=NULL;
struct node *new,*temp;
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	add_after_node(20,25);
	display();
}
int add(int n)
{
	new=malloc(sizeof(struct node));
	new->n=n;
	new->p=NULL;
	if(start==NULL)
	{
		start=new;
		return(0);
	}
	for(temp=start;temp->p!=NULL;temp=temp->p);
	temp->p=new;
}
int add_after_node(int m,int num)
{
	for(temp=start;temp->p!=NULL;temp=temp->p)
	{
		if(temp->n==m)
		{
			new=malloc(sizeof(struct node));
			new->n=num;
			new->p=temp->p;
			temp->p=new;
		}
	}
}
int display(int n)
{
	struct node *temp;

	for(temp=start;temp!=NULL;)
	{
		printf("%d\n",temp->n);
		temp=temp->p;
	}
}

