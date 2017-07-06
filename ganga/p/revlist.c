#include <stdio.h>
#include <stdlib.h>
int addnode(int);
int display(void);
struct node
{
	int value;
	struct node *next;
};
struct node *h=NULL;
int j;
int main()
{
	/*addnode(10);
	addnode(90);
	addnode(20);
	addnode(40);
	addnode(60);
	display();*/
	revlist();
}

int addnode(int n)
{
	struct node *temp=NULL;
	struct node *ptr=NULL;
	ptr=malloc(sizeof(struct node));
	ptr->value=n;
	ptr->next=NULL;
	if(h==NULL)
	{
		h=ptr;
		temp=h;
		return 0;
	}
	for(temp=h;temp->next!=NULL;temp=temp->next)
	{
	}
	temp->next=ptr;
	return 0;
}
int display(void)
{
	struct node *temp=NULL;
	temp=h;
	while(temp!=NULL)
	{
		printf("%d ",temp->value);
		temp=temp->next;
	}
	printf("\n");
	return 0;	
}
int revlist(void)
{
	struct node *c=NULL;
	struct node *temp=NULL;
	struct node *ptr=NULL;
	for(temp=h;temp->next!=NULL;temp=temp->next);
	ptr=temp;
	c=ptr;
	while(ptr!=h)
	{
		for(temp=h;temp->next!=ptr;temp=temp->next);
		ptr->next=temp;
		ptr=ptr->next;
	}
	ptr->next=NULL;
	for(temp=c;temp!=NULL;temp=temp->next)
	{
		printf("%d  ",temp->value);
	}
	return 0;
}



