#include<stdio.h>
#include <stdlib.h>
int add( int );
void display(void);
void reverse(void);
struct node 
{
	int n;
	struct node *p;	
};
struct node *t;
struct node *h = NULL;
main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	display();
	reverse();
	display();
}


int add( int num)
{
	int a; 
	struct node *i;
	struct node *j;
	struct node *temp = h;
	struct node *k;
	t = malloc(sizeof(struct node));
	t -> n = num;
	t -> p = NULL;
	if( h == NULL)
	{
		h = t;
		k=h;
		return 0;
	}
	while (temp ->p != NULL)
	{
		temp = temp ->p;
	}
	temp ->p = t;
	/*for(i=k;i!=NULL;i=i->p)
	    for(j=i->p;j!=NULL;j=j->p)
		   if(i->n > j->n)
		   {
		   a=i->n;
		   i->n=j->n; 
		   j->n=a;
		   }*/
	return 0 ;
}
void reverse(void)
{
struct node *temp;
struct node *next;
struct node *prev=NULL;
temp=h;
while(temp!=NULL)
{
next=temp->p;
temp->p=prev;
prev=temp;
temp=next;
}
h=prev;
//return(0);
}
void display(void)
{
struct node *temp;
for(temp=h;temp!=NULL;temp=temp->p)
printf("%d\n",temp->n);
}
