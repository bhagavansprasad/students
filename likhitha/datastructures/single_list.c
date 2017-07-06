#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

struct node *header;
main()
{
	int total=0 , t=0, n = 20;
	add_node(50);
	add_node(20);
	add_node(40);
	insert_first(10);
	add_node(30);
	add_node(90);
	insert_last(70);
	insert_by_pos(45, 3);
	printf("inserting the elements are : ");
	display();
	total=node_count();
	printf("count is %d\n",total);
	t=count(n);
	if(t==1)
	{
		printf("node is found : %d\n", n);
	}
	else
		printf("%d : node is not found\n", n);
	delete(30);
	delete(20);
	delete(60);
	printf("after deletion : ");
	display();
	sort();
	printf("sorting elements are :");
	display();
}

int add_node(int n)
{
	struct node *new = NULL,*temp = NULL;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;

	if(header==NULL)
	{
		header=new;
		return;
	}

	for(temp=header ; (temp->next)!=NULL ; temp=(temp->next));

	temp->next=new;
}

int display()
{
	struct node *temp = NULL;
	for(temp = header ; temp != NULL; temp = temp -> next)
	{
		printf("%d ", temp -> data);
	}
	printf("\n");
}

int delete(int n)
{
	struct node  *temp=NULL, *prev = NULL;

	for(temp=header ; temp!=NULL ; prev = temp ,temp=temp->next)
	{
		if( temp -> data == n)
		{
			if( header -> data == n)
			{
				header = header -> next;
				return;
			}
			else
				prev-> next  = temp -> next ;
			return;
		}
	}
}

int node_count()
{
	struct node *temp;
	int count =0;
	for(temp=header ; temp!=NULL ; temp=temp->next)
	{
		count++;
	}
	return count;
}

int count(int n)
{
	struct node *temp;
	int flag=0;
	for(temp=header ; temp!=NULL ; temp=temp->next)
	{
		if(temp->data==n)
		{
			return(1);
		}
	}
	if(flag==0)
		return 0;
}

int insert_first(int n)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=n;
	new->next=header;
	header=new;
}

int insert_last(int n)
{
	struct node *new,*temp;
	new=(struct node *)malloc(sizeof(struct node));

	for(temp=header ; temp!=NULL ; temp=temp->next)
	{
		if(temp->next==NULL)
		{
			temp->next=new;
			new->data=n;
			new->next=NULL;
			return ;
		}
	}
}

int  insert_by_pos(int n, int pos)
{
	struct node *new , *temp , *prev ;
	int i;
	new=(struct node *)malloc(sizeof(struct node));
	for(temp=header , i=1 ; temp!=NULL ; i++,prev = temp,temp=temp->next)
	{
		if (pos == 1)
		{
			new->data=n;
			new->next=header;
			header=new;
			return;
		}
		else if(i == pos)
		{
			prev->next=new;
			new->data=n;
			new->next=temp;
			return;
		}
	}
}
int sort()
{
	struct node *temp , *prev ;
	int swap = 0;
	for(prev=header ; prev!=NULL ; prev=prev->next)
	{
		for(temp=prev->next ; temp!=NULL ; temp=temp->next)
		{
			if(prev->data > temp->data)
			{
				swap=temp->data;
				temp->data=prev->data;
				prev->data=swap;
			}
		}
	}
}
