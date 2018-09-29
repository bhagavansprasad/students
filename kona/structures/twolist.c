#include<stdio.h>
#include<stdlib.h>
int add(int,int);
struct node1
{  
	int n;
	struct node1 *p;
};
struct node1 *h1=NULL;
struct node1 *h2=NULL;
void display(struct node1 *t);
main()
{
	add(10,1);
	add(20,1);
	add(30,1);
	add(40,1);
	add(50,1);
	add(90,2);
	add(80,2);
	add(40,2);
	add(20,2);
	display(h1);
	//struct node *inc = intersect(h1,h2);
	//display(inc);
}
int add(int v,int x)
{
	if(x==2 || x==1)
	{

		struct node1 *temp=h1;
		struct node1 *new;

		new = (struct node1*)malloc(sizeof(struct node1));

		new->n = v;
		new->p = NULL;

		if(h1 == NULL)
		{
			h1 = new;
			return 0;
		}
		for(temp=h1;temp->p!=NULL;temp=temp->p);
		temp->p=new;

		return 0;
	}
}
void display(struct node1 *t)
{
	struct node1 *temp=t;
	for(temp=t;temp!=NULL;)
	{
		printf("the value is %d\n",temp->n);
		printf("\n");
		temp=temp->p;
	}
}
struct node *intersect(struct node *h1,struct node *h2)
{
	int l1=length(h1),l2=length(h2);
	struct node *p1=h1,*p2=h2;
	if(l1>l2)
	{
		int c=0;
		while(c<(l1-l2))
		{
			p1=p1->link;
			c++;
		}
	}
	else
	{
		int c=0;
		while(c(l2-l1))
		{
			p2=p2->link;
			c++;
		}
	}
	while(p1!=NULL && p2!=NULL)
	{
		if(p1==p2)
		{
			return p1;
		}
		else
		{
			p1=p1->link;
			p2=p2->link;
		}
	}
	return NULL;
}
