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
	insert_middle(3,25);
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
int insert_middle(int pos,int num)
{
struct node *middle;
int c=0;
{
for(temp=start;temp->p!=NULL;temp=temp->p)
{
c++;
if(c==pos-1)
{
	middle=malloc(sizeof(struct node));
	middle->n=num;
	middle->p=temp->p;
	temp->p=middle;
}
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

