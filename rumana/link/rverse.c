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
	display();
	printf("\n");
	revers_link();
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
int revers_link()
{
	struct node *next,*pre;
	temp=start;
	pre=NULL;
	while(temp!=NULL)
	{
		next=temp->p;
		temp->p=pre;
		pre=temp;
		temp=next;
	}
	start=pre;
	//return(start);
}
void display(void)
{
 struct node *i;
	for(i=start;i!=NULL;)
	{
		printf("%d\n",i->n);
		i=i->p;
	}
}

