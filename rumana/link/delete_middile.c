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
	delete_middile(30);
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
int delete_middile(int num)
{
	struct node *pre;
	for(temp=start->p,pre=start;temp->p!=NULL;temp=temp->p,pre=pre->p)
	{
		if(temp->n==num)
		{
			pre->p=temp->p;
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

