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
	addnode(6);
	addnode(50);
	addnode(1);
	addnode(100);
	display();
}

int addnode(int n)
{
	struct node *temp=NULL;
	struct node *ptr=NULL;
	struct node *c=NULL;
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
	if(ptr->value>=temp->value)
		temp->next=ptr;
	else if(ptr->value<h->value)
	{
		ptr->next=h;
		h=ptr;
	}
	else
	{
		temp=h->next;
		c=h;
		while(c!=NULL)
		{
			if(ptr->value<temp->value)
			{
				c->next=ptr;
				ptr->next=temp;
				return 0;
			}
			c=temp;
		   temp=temp->next;

		}
	}
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

