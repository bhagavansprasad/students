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
//	display();
//	delete_node(10);
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
/*int delete_node(int num)
{
	struct node *pre,*temp;
	for(pre=start,temp=start->q;temp!=NULL;pre=pre->q,temp=temp->q)
	{
		if(pre->n==num)
		{
			start=pre->q;
			temp->p=NULL;
		}
		if(temp->n==num)
		{
			pre->q=temp->q;
			temp->p=pre;
		}
	}
}*/
int display(int n)
{
	struct node *temp,*pre;
	for(temp=start;temp!=NULL;temp=temp->q)
	{
		printf("%d\n",temp->n);
	}
	for(;pre!=NULL;)
	{
		printf("%d\n",pre->n);
		pre=pre->p;

	}

}


