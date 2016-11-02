#include"stdio.h"
#include"stdlib.h"

struct node
{
	int d;
	struct node *next,*prev;
};

struct node *h=NULL;

int add_double(int val)
{
	struct node *temp;
	struct node *new=malloc(sizeof(struct node));
	new->d=val;
	new->next=new->prev=NULL;
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	for(temp=h;temp->next!=NULL;temp=temp->next);
	temp->next=new;
	new->prev=temp;
	return 0;
}

int search(int val)
{
	struct node *temp;
	if(h==NULL)
	{
		printf("THERE ARE NO NODES TO SEARCH");
		return 1;
	}
	for(temp=h;temp!=NULL;temp=temp->next)
	{
		if(temp->d==val)
		{
			printf("THE ELEMENT IS PRESENT IN THE LIST");
			return 0;
		}
	}
	printf("THE SEARCHING VAL IS NOT PRESTNE IN THE LIST");
	return 0;

}


void display()
{
	printf("\r\n");
	struct node *temp;
	for(temp=h;temp!=NULL;temp=temp->next)
	{
		printf("%d \t",temp->d);
	}
}

int main()
{
	add_double(10);
	add_double(20);
	add_double(30);
	add_double(40);
	add_double(50);
	add_double(60);
	display();
	search(70);
	return 0;
}
