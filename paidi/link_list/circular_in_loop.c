#include<stdlib.h>
#include<stdio.h>
void add_loop(int);
void display();
void add_loop1();
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head=NULL;


main()
{
	add_loop(20);
	display();
	add_loop(30);
	display();
	add_loop(40);
	display();
	add_loop(50);
	display();
	add_loop(60);
	display();
	add_loop(70);
	display();
	add_loop(80);
	display();
        add_loop1();
        display(); 
}

void add_loop (int x)
{
	node *new,*temp;
	new=malloc(sizeof( node));

	printf("-->%s %d, :%d\n", __FUNCTION__, __LINE__, x);

	new->data=x;
	new->next=NULL;

	if(head==NULL)
	{
		head=new;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=new;
	}

}

void add_loop1( )
{
  node *temp,*old;

	for(old=head;old->next!=NULL;old=old->next)
	{
		temp=head;
		while(old->next!=NULL && old!=temp)
		{
			if(old->next==temp)
			{
				printf("loop is found\n");
				//	return 0;
			}
			temp=temp->next;
		}
		printf("loop is not found\n");
		 //return 0;
	}

}
void display()
{
	node *temp;	
	temp=head;

	printf("-->%s\n", __FUNCTION__);

	while(temp!=NULL)
	{
		printf("%4d",temp->data);
		temp=temp->next;	 
	}

	printf("\n");
}


