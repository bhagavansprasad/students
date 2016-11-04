#include <stdio.h>
#include <stdlib.h>
//void push(struct node**,int);
//void printlist(struct node *);
struct node *getintersect(struct node *,struct node *);
//int ispresent(struct node *,int);
struct node
{
		int data;
		struct node *next;
};
main()
{
	struct node *h1=NULL;
	struct node *h2=NULL;
	//struct node *h3=NULL;
	push(&h1,10);
	push(&h1,20);
	push(&h1,30);
	push(&h1,40);
	push(&h1,50);
	printlist(h1);
	printf("\n");
	push(&h2,60);
	push(&h2,70);
	push(&h2,20);
	push(&h2,40);
	push(&h2,10);
	printlist(h2);
	printf("\n");
	struct node *h3 = getintersect(h1,h2);
	printlist(h3);
}
void push(struct node** head,int val)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=val;
	new->next=(*head);
	(*head)=new;
}
void printlist(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
}
struct node *getintersect(struct node *h1,struct node *h2)
{
	struct node *result=NULL;
	struct node *t=h1;
	while(t!=NULL)
	{
		if(ispresent(h2,t->data))
		push(&result,t->data);
		t=t->next;
	}
	return result;
}
int ispresent(struct node *h,int data)
{
	struct node *t=h;
	while(t!=NULL)
	{
		if(t->data==data)
		return 1;
		t=t->next;
	}
	return 0;intersection.c
}
