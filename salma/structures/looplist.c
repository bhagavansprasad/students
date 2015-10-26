#include<stdio.h>
#include<stdlib.h>
int add(int);
void display(void);
void formloop(void);
struct node
{
	int n;
	struct node *p;
};
struct node *h=NULL;
main()
{
  int d;
	add(10);
	add(20);
	add(30);
	add(40);
	add(50);
	display();
	formloop();
	//	display();
	d=detectloop();
	if(d==0)
	printf("there is a loop\n");
	else 
	printf("there is no loop\n");
}
int  add(int v)
{
	struct node *t;
	struct node *temp=h;
	t=malloc(sizeof(struct node));
	t->n=v;
	t->p=NULL;
	if(h==NULL)
	{
		h=t;
		return 0;
	}
	while(temp->p != NULL)
		temp=temp->p;
	temp->p=t;
	return 0;
}
void display()
{
	struct node *temp=h;
	while(temp!=NULL)
	{
		printf(" %d \n",temp->n);
		temp=temp->p;
	}
}
void formloop()
{
	struct node *temp=h;
	while(temp->p != NULL)
		temp=temp->p;
	temp->p=h->p;
}
int detectloop()
{
	struct node *first=h;
	struct node *last=h;
	//struct node *temp=h;
	while(first && last && last->p)
	{
		first=first->p;
		last=last->p->p;
		if(first==last)
			return 0;
	}
	return 1;
}
