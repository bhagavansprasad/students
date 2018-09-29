#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head,*head1,*head2;
node *Head[2];
void sumnodevals(node *head1,node *head2);
void display();

void main()
{
	int n[2]={7923,62},i,r1,r2;

	for(i=0;i<2;i++)
	{

		head=NULL;
		while(n[i]!=0)
		{
			r1=n[i]%10;
			addnode(r1);
			n[i]=n[i]/10;
		}
		Head[i]=head;
		display();
	}
sumnodevals(Head[0],Head[1]);
}	
int addnode(int r1)
{
	node *new,*temp;
	new=malloc(sizeof(node));
	new->data=r1;
	if(head==NULL)
	{
		head=new;
		new->next=NULL;
	}
	else
	{
		new->next=head;
		head=new;
	}
}
void sumnodevals(node *head1,node *head2)
{
	node *t3=NULL,*t4=NULL,*t1=NULL,*t2=NULL;
	int k,c=0,m;
	head=NULL;
	for(;t1!=head1&&t2!=head2;)
	{
		for(t1=head1;t1->next!=t3;t1=t1->next);
		t3=t1;
		for(t2=head2;t2->next!=t4;t2=t2->next);
		t4=t2;
		k=t3->data+t4->data+c;
		m=k%10;
		addnode(m);
		c=k/10;
	}
	display();
}
void display()
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("|%d|-->",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

