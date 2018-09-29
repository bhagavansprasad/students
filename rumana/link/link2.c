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
	insert_last(50);
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
int insert_last(int num)
{
struct node *last;
{
	last=malloc(sizeof(struct node));
	last->n=num;
	last->p=NULL;
	new->p=last;
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



