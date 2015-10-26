#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *p;
	int n;
	struct node *q;
};
struct node *start=NULL;
struct node *new;
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	display();
}
int add(int num)
{
	struct node *temp;
	new=malloc(sizeof(struct node));
	new->p=NULL;
	new->n=num;
	new->q=NULL;
	if(start==NULL)
	{
		start=new;
		return(0);
	}
	for(temp=start;temp->q!=NULL;temp=temp->q);
	new->p=temp;
	temp->q=new;
}
int display(int n)
{
	struct node *temp;
	for(temp=start;temp->q!=NULL;temp=temp->q)
	{
		printf("%d\n",temp->n);
	}
	if(temp->q==NULL)
	{
	printf("%d\n",temp->n);
	}
	for(;temp!=NULL;)
	{
		printf("%d\n",temp->n);
		temp=temp->p;

	}

}


