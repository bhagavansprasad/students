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
	addnode(10);
	addnode(90);
	addnode(20);
	addnode(40);
	addnode(60);
	display();
	apop();
	display();

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
int apop()
{
	h=h->next;
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

