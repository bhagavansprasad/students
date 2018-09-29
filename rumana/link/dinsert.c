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
	insert_ll(4,25);
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

int insert_ll(int pos,int num)
{
	struct node *temp,*cur;
	int c=0;
	for(temp=start;temp!=NULL;temp=temp->q)
	{
		if(c==pos-1)
		{
			new=malloc(sizeof(struct node));
			new->p=NULL;
			new->n=num;
			new->q=temp;
			start=new;
			temp->p=new;
			break;

		}
	}
	{
		for(temp=start,cur=start->q;cur!=NULL;temp=temp->q,cur=cur->q)
		{
			c++;
			if(c==pos-1)
			{
				new=malloc(sizeof(struct node));
				new->p=temp;
				new->n=num;
				new->q=temp->q;
				temp->q=new;
				cur->p=new;
			}
			if(cur->P!=NULL&&cur->q==NULL)
			{		
			new=malloc(sizeof(struct node));
				new->p=cur;
				new->n=num;
				new->q=NULL;
				cur->q=new;
			}
		}

	}
}
int display(int n)
{
	struct node *temp,*pre;
	for(temp=start;temp!=NULL;temp=temp->q)
	{
		printf("%d\n",temp->n);
	}
	//	for(;pre!=NULL;)
	//	{
	//		printf("%d\n",pre->n);
	//		pre=pre->p;
	//
	//	}

}


