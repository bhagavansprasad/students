#include<stdio.h>
#include<stdlib.h>
int add(int);
int delete(int);
void display(void);
struct node 
{
	struct node *p1;
	int n;
	struct node *p2;
};
struct node *h=NULL;
struct node *t=NULL;
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
    display();
    delete(20);
	display();
	delete(10);
	display();
	delete(40);
	display();
}
int add(int value)
{
	struct node *temp=h;
	t= /*(struct node *)*/malloc(sizeof(struct node));
	t->p1=NULL;
	t->n=value;
	t->p2=NULL;
	if(h==NULL)
	{
		h=t;
		return(0);
	}
	while(temp->p2!=NULL)
	{
		temp=temp->p2;
	}
	temp->p2=t;
	t->p1=temp;
}
void display(void)
{
	struct node *temp=h, *i;
	printf("<-----this is forward list----->");
	for(i=temp;temp->p2!=NULL;temp=temp->p2)
	{
		printf("%d\t",temp->n);
	}
	if(temp->p2==NULL)
		printf("%d\n******\n",temp->n);
	printf("<-----this is reverse list----->");	
	for(;temp->p1!=NULL;temp=temp->p1)
		printf("%d\t",temp->n);
	if(temp->p1==NULL) 
		printf("%d\n*******\n",temp->n);

}
int delete(int val)
{
	struct node *temp=h;
	struct node *i;
	if(temp->n==val)
	{
		if(temp->p2==NULL)
		{
				h=NULL;
			printf("empty list\n");
			return(0);
		}
		temp=temp->p2;
		h=temp;
		temp->p1=NULL;
		return(0);
	}
	for(i=temp->p2;i!=NULL;temp=temp->p2,i=i->p2)
	{
		if(i->n==val && i->p2!=NULL)
		{
			temp->p2=i->p2;
			i->p2->p1=temp;
			return(0);
		}
	}
	  if(temp->n==val&& temp->p2==NULL)
	  {
        temp->p1->p2=NULL;
		temp->p1=NULL;
	  return(0);		
	  }
}
